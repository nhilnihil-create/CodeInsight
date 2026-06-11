#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
typedef long long ll;
const ll mod=pow(10,9)+7;

//powを使うと変なことになるので掛け算する度にmodで割る処理をする関数を定義する
ll powmod(ll a, ll b){
    ll res=1;
    for(ll i=0; i<b; i++){
        res*=a;
        res%=mod; 
    }
    return res;
}
int main()
{
    ll n;
    cin >> n;
    
    ll ans = 0;

    ans = powmod(10,n) - powmod(9,n) - powmod(9,n) + powmod(8,n);

    ans%=mod;

    ans=(ans+mod)%mod;

    cout << ans << endl;

    return 0;
}