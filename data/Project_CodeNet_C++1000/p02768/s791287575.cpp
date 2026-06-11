#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;

// n の k 乗を mod で割った余りを計算
long long power_mod(long long n, long long k, long long mod) {
    long long result = 1;
    // k を右シフトしつつ n を 2 乗していく
    while (k > 0) {
        // k の最下ビットが 1 なら、今の n を答えに掛ける
        if ((k & 1) == 1) result = (result * n) % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return result;
}

int main(){

    
    ll n,a,b;
    cin >> n >> a >> b;
    ll ka=1,kb=1;
    for(int i=1; i<=a; i++) ka=ka*i%mod;
    for(int i=1; i<=b; i++) kb=kb*i%mod;

    ll ans=power_mod(2,n,mod)-1;
    // cout << ans << endl;
    ll sum=1;
    for(ll i=0; i<a; i++) sum=sum*(n-i)%mod;
    sum=sum*power_mod(ka,mod-2,mod)%mod;
    ans=(ans-sum+mod)%mod;
    // cout << sum << endl;

    sum=1;
    for(ll i=0; i<b; i++) sum=sum*(n-i)%mod;
    sum=sum*power_mod(kb,mod-2,mod)%mod;
    ans=(ans-sum+mod)%mod;
    // cout << sum << endl;

    cout << ans << endl;
    return 0;
}