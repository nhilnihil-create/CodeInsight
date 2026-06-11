#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    for(ll i=K;i<=N+1;i++){ // iをllで宣言することを忘れない
        // 連続する数列なので最小値～最大値の間の数はすべて作れる
        // 0からi個目の和-> i*(0+i-1)/2
        // N-i+1からNまでの和-> i*(N+(N-i+1))/2
        ans += i*(N+(N-i+1))/2 - i*(0+i-1)/2 + 1;
        ans = (ans+MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}