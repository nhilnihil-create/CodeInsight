#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll N, T;


/*
  DP
  料理nまで で (時間 t、最高スコア)
*/


int d[3001];

struct food {
	int time;
	int score;
};
vector<food> f;



void calc( int n ){
	/* 0..n-1 までの料理の中から時間tまでに選ぶ場合のスコアが d[t]
	   0..n   までの料理の中から時間tまでに選ぶ場合のスコアが dd[t]
	   dd[t] = max( d[t], d[t-f[n].time] + f[n].score )
	*/
	
	for ( int t = T; t >= 1; t-- ){
		if ( t-f[n].time >= 1 ){
			d[t] = max( d[t], d[t-f[n].time] + f[n].score );
		}
	}
	d[1] = max( d[1], f[n].score ); // f[n] だけを食べた場合
}


int main(){
	cin >> N >> T;
	
	f.resize(N);
	for ( int i = 0; i < N; i++ ){
		cin >> f[i].time >> f[i].score;
	}
	
	// 時間が大きいものを先頭に
	sort(f.begin(), f.end(), [](food &l, food &r){ return -l.score-l.time*6000 < -r.score-r.time*6000; });
	
	for ( int n = 0; n < N; n++ ){
		calc( n );
	}
	
	//for ( int t = 1; t <= T; t++ ){
	//	cout << "d:" << t << " " << d[t] << endl;
	//}
	
	int best_score = 0;
	for ( int t = 1; t <= T; t++ ){
		best_score = max( best_score, d[t] );
	}
	
	cout << best_score << endl;
	
	return 0;
}

