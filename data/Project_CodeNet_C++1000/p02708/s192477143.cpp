#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
#define rrep(i,n) for(int i = n-1; i >= 0 ; i--)
typedef long long ll;
constexpr auto INFI = 2147483647;
const ll INFL = 9223372036854775807;

int main(){
    const ll MOD = 1000000007;
    ll n, k;
    ll ans;
    ll cumsum[200001];
    cin >> n >> k;
    cumsum[0] = 0;
    rep(i,200000){
        cumsum[i+1] = cumsum[i] + i + 1;
    }
    ans = 1;
    for(int i = k; i<= n; i++){
        ans += cumsum[n] - cumsum[n - i] - cumsum[i - 1] + 1;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}