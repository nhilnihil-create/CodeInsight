#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PL;
typedef pair<int,int> P;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

int main() {
    while (1) {
        int N,M; cin >> N >> M;
        if (N == 0) return 0;
        vector<P> DP(N);
        rep(i,N) cin >> DP[i].first >> DP[i].second;
        sort(DP.begin(),DP.end(),[](P x,P y){return x.second > y.second;});
        int ans = 0;
        rep(i,N) {
            if (M == 0) ans += DP[i].first * DP[i].second;
            else if (M - DP[i].first >= 0) M -= DP[i].first;
            else {
                DP[i].first -= M;
                M = 0;
                ans += DP[i].second * DP[i].first;
            }
        }
        printf("%d\n",ans);
    }
}
