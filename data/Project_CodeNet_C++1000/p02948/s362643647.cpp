#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> ab(N);
    REP(i, 0, N) cin >> ab[i].first >> ab[i].second;

    sort(ALL(ab));
    priority_queue<int> q;
    int ans = 0, j = 0;
    for (int i = 1; i <= M; i++) {
        while (j < N && ab[j].first <= i) q.push(ab[j++].second);
        if (q.size() == 0) continue;
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}