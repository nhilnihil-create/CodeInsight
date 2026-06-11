#include <algorithm>
#include <cmath>
#include <cstdint>
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
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pll> jobs(N);

    priority_queue<int> que;

    rep(i, N) {
        int a, b;
        cin >> a >> b;
        jobs[i] = MP(a, b);
    }
    sort(All(jobs));

    int cur = 0;
    ll res = 0;
    for(int i = M - 1; i >= 0; i--) {
        while(cur < jobs.size() && jobs[cur].first <= M - i) {
            que.push(jobs[cur].second);
            cur++;
        }
        if(!que.empty()) {
            res += que.top();
            que.pop();
        }
    }
    cout << res << endl;

    return 0;
}