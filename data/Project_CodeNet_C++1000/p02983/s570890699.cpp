#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define P pair<ll, ll>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 2019;


// 0~nでmodで割ったときにx余る数の数
ll f(ll n, ll x){
    if(n < x) return 0;
    ll res = (n - x) / mod + 1;
    return res;       
}

int main(){
    ll l, r;
    cin >> l >> r;
    ll ans = 2500;
    if(r - l >= 2019){
        ans = 0;
    }else{
        for (ll i = l; i < r; i++){
            for (ll j = i + 1; j <= r; j++){
                ll m = (i % mod) * (j % mod);
                m %= mod;
                ans = min(ans, m);
            }
        }
    }
    cout << ans << endl;
}