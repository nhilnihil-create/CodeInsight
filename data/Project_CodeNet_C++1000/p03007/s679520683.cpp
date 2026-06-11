#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }
    sort(All(A));
    reverse(All(A));
    using pii = pair<int, int>;
    vector<pii> ope;
    ll now = 0;
    if(A[1] > 0) {
        now = A[N - 1];
        ope.push_back(make_pair(A[0], 0));
    } else {
        now = A[0];
        ope.push_back(make_pair(A[N - 1], 0));
    }
    for(int i = 1; i < N - 1; i++) {
        if(A[i] > 0 && (A[i + 1] <= 0 || i + 1 == N - 1))
            ope.push_back(make_pair(A[i], 1));
        else
            ope.push_back(make_pair(A[i], 0));
    }
    vector<pii> res;
    rep(i, ope.size()) {
        if(ope[i].second == 0) {
            res.push_back(make_pair(now, ope[i].first));
            now = now - ope[i].first;
        } else {
            res.push_back(make_pair(ope[i].first, now));
            now = ope[i].first - now;
        }
    }

    cout << now << endl;
    rep(i, res.size()) { cout << res[i].first << " " << res[i].second << endl; }

    return 0;
}