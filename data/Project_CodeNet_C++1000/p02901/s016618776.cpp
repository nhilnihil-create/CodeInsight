#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int INF = 1001001001;

int main() {
    int N, M; cin >> N >> M;
    vector<P> key;
    rep(i, M){
        int a, b; cin >> a >> b;
        int s = 0;
        rep(j, b){
            int c; cin >> c;
            c--;
            s |= 1 << c;
        }
        key.push_back(make_pair(s, a));
    }

    vector<int> dp(1<<N, INF);
    dp[0] = 0;
    rep(i, 1<<N){
        rep(j, M){
            int k = i;
            k |= key[j].first;
            int cost = dp[i] + key[j].second;
            dp[k] = min(dp[k], cost);
        }
    }

    if(dp[(1<<N) -1] == INF){
        cout << -1 << endl;
    } else {
        cout << dp[(1<<N) -1] << endl;
    }

    return 0;
}