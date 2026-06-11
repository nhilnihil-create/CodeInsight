#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <numeric>

using namespace std;

class IndexedActivity {
public:
    int index;
    long long activity;

    IndexedActivity()
    : index(0), activity(0LL) {
    }

    IndexedActivity(int index_, long long activity_)
    : index(index_), activity(activity_) {
    }

    bool operator<(const IndexedActivity& rhs) const {
        return activity < rhs.activity;
    }
    bool operator>(const IndexedActivity& rhg) const {
        return activity > rhg.activity;
    }
};

long long maxFromNew(size_t forwardInfants, size_t backwardInfants, const vector<IndexedActivity>& sortedActivities
    , vector<vector<long long> >& memo) {
    size_t N = sortedActivities.size();
    if (forwardInfants + backwardInfants == N) {
        return 0LL;
    }
    if (memo[forwardInfants][backwardInfants] >= 0) {
        return memo[forwardInfants][backwardInfants];
    }

    const IndexedActivity& nextInfant = sortedActivities[forwardInfants + backwardInfants];

    int forwardMove = nextInfant.index - forwardInfants;
    long long letNextGoForward = (forwardMove >= 0)
        ? maxFromNew(forwardInfants + 1, backwardInfants, sortedActivities, memo) + nextInfant.activity * forwardMove
        : 0LL;

    int backwardMove = (N - 1 - backwardInfants) - nextInfant.index;
    long long letNextGoBackward = (backwardMove >= 0)
        ? maxFromNew(forwardInfants, backwardInfants + 1, sortedActivities, memo) + nextInfant.activity * ((N - 1 - backwardInfants) - nextInfant.index)
        : 0LL;

    long long ret = max(letNextGoForward, letNextGoBackward);
    memo[forwardInfants][backwardInfants] = ret;
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N, 0LL);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    //bitset<2000> path(0);
    //long long ans = maxFrom(0, path, A);
    //long long ans = greedy(A);
    vector<IndexedActivity> activities(A.size(), IndexedActivity());
    vector<vector<long long> > memo(A.size(), vector<long long>(A.size(), -1));
    for (size_t i = 0; i < A.size(); ++i) {
        activities[i] = IndexedActivity(i, A[i]);
    }
    sort(activities.begin(), activities.end(), greater<IndexedActivity>());
    long long ans = maxFromNew(0, 0, activities, memo);
    cout << ans << endl;
    return 0;
}
