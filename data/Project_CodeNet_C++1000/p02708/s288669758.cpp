#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll N,K;
    cin >> N >> K;
    
    ll ans = 0;

    for (ll k=K; k<=N+1; k++) {
        ans += (N+(N-k+1))*k/2 - (k-1)*k/2 + 1;
        ans %= MOD;
        //cout << (N+(N-k+1))*k/2 <<" " <<  (k-1)*k/2  << endl;
    }
    cout << ans << endl;
}
