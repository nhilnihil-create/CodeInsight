#include <bits/stdc++.h>
#include<cmath>
#define N 100005
#define A 1000005
#define MOD 1000000007 // //100000000 998244353 //
#define inf 1000000000000000000
#define ll long long
//#define M_PI 3.141592653589793238463

using namespace std;

#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define ft first
#define sd second
#define pb push_back
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n-1; i >= 0; i--)
#define itr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define mem(a, b) memset(a, (ll)b, sizeof(a))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define edge(v, x, y) v[x].pb(y); v[y].pb(x);
#define popcount __builtin_popcount
#define ANS(s) {cout << s << "\n"; return;}

//~~~~~~fancy print~~~~~~~//
#define printpii(a) cout << a.ft << " " << a.sd << endl;
#define printpiii(a) cout << a.ft << " " << a.sd.ft << " " << a.sd.sd << endl;
#define print(a, n) rep(i, n) cout << a[i] << " "; cout << endl;
#define printv(v) for(auto x: v)cout << x << " "; cout << endl;
#define printm(a, n, m) rep(i, n) { rep(j, m) cout << a[i][j] << "\t"; cout << endl;}

ll lx[4] = {0, 0, 1, -1};
ll ly[4] = {1, -1, 0, 0};
ll dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
ll dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout << setprecision(12) << fixed;}
ll lcm(ll a, ll b) {return (a*b)/__gcd(a, b); }

bool sol(string s, ll x, ll y)
{
    ll dp[s.size()+5]; mem(dp, 0);
    dp[x] = 1;
    for(ll i = x; i <= y; i++){
        if(dp[i] == 0) continue;
        if(s[i+1] != '#') dp[i+1] = 1;
        if(s[i+2] != '#') dp[i+2] = 1;
    }
    return dp[y] == 1;
}

void solve()
{
    ll n, a, b, c, d, f = 0;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s; a--, b--, c-- , d--;

    ll dp[s.size()+5]; mem(dp, 0);
    if(c < d){
        for(ll i = b; i < d; i++){
            if(s[i] == s[i+1] && s[i] == '#') f = 1;
        }
        for(ll i = a; i < c; i++){
            if(s[i] == s[i+1] && s[i] == '#') f = 1;
        }
    }
    else{
        for(ll i = a; i < c; i++){
            if(s[i] == s[i+1] && s[i] == '#') f = 1;
        }
        ll fff = 0;
        for(ll i = b; i <= d; i++){
            if(s[i-1] == s[i+1] && s[i] ==  s[i+1] && s[i] == '.') fff = 1;
        }
        if(fff == 0) f = 1;
    }


    if(!f) ANS("Yes");
    ANS("No");

}
int main(){
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    fast();
    ll t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
