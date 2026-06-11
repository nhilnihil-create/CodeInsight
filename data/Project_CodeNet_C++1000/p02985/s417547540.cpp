#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N - 1), b(N - 1);
    vector< vector<P> > edges(N);
    rep(i,N-1) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        edges[a[i]].push_back(make_pair(b[i], i));
        edges[b[i]].push_back(make_pair(a[i], i));
    }
    vector<bool> visited(N - 1, false);
    long long ans = 1;
    queue<LLP> que;
    que.push(make_pair(0, K));
    while (!que.empty()) {
        LLP p = que.front(); que.pop();
        ans = ans * p.second % MOD;
        if (ans <= 0) {
            cout << 0 << endl;
            return 0;
        }

        long long k_now = (p.second == K ? K - 1 : K - 2);
        
        for (int i = 0; i < edges[p.first].size(); i++) {
            if (!visited[edges[p.first][i].second]) {
                visited[edges[p.first][i].second] = true;
                que.push(make_pair(edges[p.first][i].first, k_now--));
            }
        }
    }

    cout << ans << endl;
    return 0;
}