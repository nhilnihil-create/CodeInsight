#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

bool comp(vi& lhs, vi& rhs) {
    if (lhs[1] != rhs[1]) {
        return lhs[1] > rhs[1];
    }
    else {
        return lhs[0] < rhs[0];
    }
}
int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> pjobs(N, vi(2));
    rep(i, N) cin >> pjobs[i][0] >> pjobs[i][1];
    sort(ALL(pjobs), comp);
    set<int> Dfree;
    ll score = 0;
    for (int i = 0; i < M + 1; i++) {
        Dfree.insert(i);
    }
    for (int i = 0; i < N; i++) {
        int a = pjobs[i][0];
        int b = pjobs[i][1];
        auto iter = Dfree.lower_bound(a);
        if (iter != Dfree.end()) {
            score += b;
            Dfree.erase(iter);
        }
    }
    cout << score << endl;
}