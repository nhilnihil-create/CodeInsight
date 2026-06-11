#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using ll = long long;
using P = pair<ll,ll>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}




int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    map<ll,ll> map;
    bool zero = false;
    rep(i,N){
        cin >> a[i];
        map[a[i]] += 1;
        if(a[i] != 0) zero = true;
    }

    ll count = 0;
    bool val = true;
    bool bnum = true;
    bool bxor = true;
    ll tmp = 0;
    ll ixor;
    for(auto x:map){
        if(count == 0) ixor = x.first;
        else ixor ^= x.first;
        if(count > 0){
            if(tmp != x.second) bnum = false;
        }
        tmp = x.second;
        count++;        
    }
    if(count != 3) val = false;
    if(ixor != 0) bxor = false;

    ll countzero = 0;
    ll tmp2 = 0;
    for(auto x:map){
        if(x.first == 0) tmp = x.second;
        else tmp2 = x.second;
        if(count > 0){
            if(tmp*2 == tmp2){
                bnum = true;
                bxor = true;
            }
        }
        countzero++;        
    }
    if(countzero == 2) val = true;

    string ans = "Yes";
    if((!bnum || !val || !bxor )&& zero) ans = "No";

    cout << ans << endl;

    return 0;
}
//Ctrl+Shift+Bでコンパイルと実行を行ってデバッグすること