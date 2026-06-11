#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    ll n,k; cin >> n >> k;
    string s; cin >> s;
    ll ans = 0,count = 0;

    rep(i,n-1){
        if(s[i] == s[i+1]) ans ++;
        else if(s[i] == 'R' && s[i+1] == 'L')count ++;
    }

    if(count == 1) cout << ans + 1;
    else if(k >= count + 1) cout << (ans + 2*(count) + ((s[0] != s[n-1])?1:0));
    else cout << ans + 2*(k);

}
