#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

vector<ll> m(1001,0);

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main(){

    ll n; cin >> n;
    char mem;
    ll ans = 1;
    
    string s; cin >> s;
    
    mem = s[0];
    
    for(int i = 1; i < s.length(); i ++){
        if(s[i] == mem){
            //なんも
        }else{
            ans ++;
            mem = s[i];
        }
    }
    
    cout << ans;
    
    return 0;
}