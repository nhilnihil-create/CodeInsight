/**
 * Longitudinal Report Engine
 * Tracks student progress over time and calculates "Mastery Velocity"
 * Implements Pillar 9 from the gemini.md research objectives
 */

const db = require('../config/db');

/**
 * Calculate mastery velocity for a student across multiple exercises in a concept
 * @param {number} studentId - ID of the student
 * @param {number} conceptId - ID of the concept to track
 * @param {number} sectionId - ID of the section (optional, for context)
 * @returns {Object} Mastery velocity metrics and progress data
 */
async function calculateMasteryVelocity(studentId, conceptId, sectionId = null) {
  try {
    // Build query conditions
    let whereConditions = 'cs.student_id = $1 AND c.id = $2';
    let queryValues = [studentId, conceptId];

    if (sectionId) {
      whereConditions += ' AND ex.section_id = $3';
      queryValues.push(sectionId);
    }

    // Get student's CDS scores for this concept over time — using exercise_concept_tags (primary)
    const scoresRes = await db.query(
      `SELECT cs.cds, cs.classification, cs.computed_at,
              ex.title AS exercise_title, ex.id AS exercise_id
       FROM cds_scores cs
       JOIN exercises ex ON cs.exercise_id = ex.id
       JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id AND ect.is_primary = true
       JOIN concepts c ON c.id = ect.concept_id
       WHERE ${whereConditions}
       ORDER BY cs.computed_at ASC`,
      queryValues
    );

    const scores = scoresRes.rows;

    if (scores.length < 2) {
      return {
        studentId,
        conceptId,
        masteryVelocity: 0,
        progressTrend: 'insufficient_data',
        message: 'Need at least 2 exercises to calculate mastery velocity',
        scores: scores,
        recommendations: ['Complete more exercises in this concept to track progress.']
      };
    }

    // Calculate mastery velocity (improvement rate over time)
    const firstScore = scores[0].cds;
    const lastScore = scores[scores.length - 1].cds;
    const timeSpanDays = calculateTimeSpanDays(
      scores[0].computed_at,
      scores[scores.length - 1].computed_at
    );

    let masteryVelocity = 0;
    let progressTrend = 'stable';

    if (timeSpanDays > 0) {
      // Velocity = (final_score - initial_score) / time_in_days
      masteryVelocity = ((lastScore - firstScore) / timeSpanDays) * 100; // Percentage per day

      // Categorize trend
      if (masteryVelocity > 0.5) {
        progressTrend = 'improving_rapidly';
      } else if (masteryVelocity > 0.1) {
        progressTrend = 'improving';
      } else if (masteryVelocity > -0.1) {
        progressTrend = 'stable';
      } else if (masteryVelocity > -0.5) {
        progressTrend = 'declining';
      } else {
        progressTrend = 'declining_rapidly';
      }
    }

    // Calculate consistency (standard deviation of scores)
    const cdsValues = scores.map(s => s.cds);
    const consistency = calculateConsistency(cdsValues);

    // Generate insights and recommendations
    const insights = generateInsights(scores, masteryVelocity, progressTrend, consistency);
    const recommendations = generateRecommendations(scores, masteryVelocity, progressTrend, conceptId);

    // Get concept name
    const conceptRes = await db.query(
      'SELECT name FROM concepts WHERE id = $1',
      [conceptId]
    );
    const conceptName = conceptRes.rows.length > 0 ? conceptRes.rows[0].name : 'Unknown';

    return {
      studentId,
      conceptId,
      conceptName,
      masteryVelocity: Number(masteryVelocity.toFixed(4)),
      progressTrend,
      firstScore: Number(firstScore.toFixed(4)),
      lastScore: Number(lastScore.toFixed(4)),
      scoreImprovement: Number((lastScore - firstScore).toFixed(4)),
      timeSpanDays,
      consistency: Number(consistency.toFixed(4)),
      totalExercises: scores.length,
      scores: scores.map(s => ({
        exerciseId: s.exercise_id,
        exerciseTitle: s.exercise_title,
        cds: Number(s.cds.toFixed(4)),
        classification: s.classification,
        date: s.computed_at
      })),
      insights,
      recommendations,
      generatedAt: new Date().toISOString()
    };

  } catch (error) {
    console.error('Error calculating mastery velocity:', error);
    return {
      studentId,
      conceptId,
      error: 'Failed to calculate mastery velocity',
      message: error.message
    };
  }
}

/**
 * Calculate time span in days between two dates
 * @param {Date|string} startDate - Start date
 * @param {Date|string} endDate - End date
 * @returns {number} Time span in days
 */
function calculateTimeSpanDays(startDate, endDate) {
  const start = new Date(startDate);
  const end = new Date(endDate);
  const diffTime = Math.abs(end - start);
  return Math.ceil(diffTime / (1000 * 60 * 60 * 24));
}

/**
 * Calculate consistency (inverse of coefficient of variation)
 * @param {Array<number>} values - Array of CDS scores
 * @returns {number} Consistency score (0-1, higher is more consistent)
 */
function calculateConsistency(values) {
  if (values.length < 2) return 1.0;

  const mean = values.reduce((sum, val) => sum + val, 0) / values.length;
  if (mean === 0) return 1.0;

  const variance = values.reduce((sum, val) => sum + Math.pow(val - mean, 2), 0) / values.length;
  const stdDev = Math.sqrt(variance);

  // Coefficient of variation
  const cv = stdDev / mean;

  // Convert to consistency score (0-1)
  // Lower CV = higher consistency
  return Math.max(0, Math.min(1, 1 - cv));
}

/**
 * Generate insights based on progress data
 * @param {Array} scores - Array of score objects
 * @param {number} velocity - Mastery velocity
 * @param {string} trend - Progress trend
 * @param {number} consistency - Consistency score
 * @returns {Array<string}} Insights
 */
function generateInsights(scores, velocity, trend, consistency) {
  const insights = [];

  // Trend-based insights
  if (trend.includes('improving')) {
    insights.push(`Student shows ${trend.replace('_', ' ')} progress in this concept.`);
  } else if (trend.includes('declining')) {
    insights.push(`Student's performance is ${trend.replace('_', ' ')}; may need review or additional practice.`);
  } else {
    insights.push(`Student's performance is stable; consider challenging problems to promote growth.`);
  }

  // Consistency insights
  if (consistency > 0.8) {
    insights.push('Performance is highly consistent across exercises.');
  } else if (consistency > 0.5) {
    insights.push('Performance shows moderate consistency.');
  } else {
    insights.push('Performance varies significantly between exercises; may indicate gaps in understanding.');
  }

  // Recent performance insight
  const recentScore = scores[scores.length - 1].cds;
  if (recentScore >= 0.8) {
    insights.push('Recent performance indicates strong mastery of the concept.');
  } else if (recentScore >= 0.6) {
    insights.push('Recent performance shows developing proficiency.');
  } else if (recentScore >= 0.4) {
    insights.push('Recent performance suggests basic understanding with room for improvement.');
  } else {
    insights.push('Recent performance indicates significant difficulty with the concept.');
  }

  return insights;
}

/**
 * Generate recommendations based on progress data
 * @param {Array} scores - Array of score objects
 * @param {number} velocity - Mastery velocity
 * @param {string} trend - Progress trend
 * @param {number} conceptId - Concept ID
 * @returns {Array<string}} Recommendations
 */
function generateRecommendations(scores, velocity, trend, conceptId) {
  const recommendations = [];

    // Trend-based recommendations
    if (trend.includes('declining')) {
      recommendations.push('Review fundamental concepts and provide targeted practice problems.');
      recommendations.push('Consider one-on-one assistance to identify specific areas of confusion.');
    } else if (trend.includes('improving') && velocity < 0.3) {
      recommendations.push('Continue current pace; consider slightly more challenging problems.');
    } else if (trend.includes('improving_rapidly')) {
      recommendations.push('Student is ready for advanced topics or enrichment activities.');
    }

    // Consistency-based recommendations
    const cdsValues = scores.map(s => s.cds);
    const consistency = calculateConsistency(cdsValues);

    if (consistency < 0.5) {
      recommendations.focus_on = 'Consistency';
      recommendations.push('Focus on building reliable problem-solving habits.');
      recommendations.push('Encourage careful reading and systematic approach to problems.');
    }

    // Mastery-based recommendations
    const latestScore = scores[scores.length - 1].cds;
    if (latestScore < 0.4) {
      recommendations.push('Provide additional foundational exercises before advancing.');
      recommendations.push('Consider pairing with a peer for collaborative problem-solving.');
    } else if (latestScore > 0.8) {
      recommendations.push('Challenge with complex, multi-concept problems.');
      recommendations.push('Consider having the student explain concepts to peers (teaching reinforces learning).');
    }

    // Exercise count recommendation
    if (scores.length < 3) {
      recommendations.push('Complete more exercises in this concept for better tracking.');
    }

    // Default recommendation if none generated
    if (recommendations.length === 0) {
      recommendations.push('Continue regular practice and seek feedback on challenging problems.');
    }

    return recommendations;
}

module.exports = { calculateMasteryVelocity };