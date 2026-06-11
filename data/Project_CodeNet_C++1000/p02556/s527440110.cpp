#include <bits/stdc++.h>
using namespace std;

#define fa(x,v) for(auto x:v)
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define spc " "
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(s) (ll)int(s.length())
#define sz(v) (ll)int(v.size())
#define MOD 1000000007

void Fast_IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef rsd511
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    #ifndef rsd511
    #define trace(...) {}
    #define cotra(...) {}
    #endif
} 

// Code Here

int main()
{
    Fast_IO();
    ll n; cin >> n;
    vector < pair<ll,ll> > p(n);
    f(i,0,n-1) cin >> p[i].ff >> p[i].ss;
    vector <ll> plus, minus;
    f(i,0,n-1) plus.pb(p[i].ff + p[i].ss), minus.pb(p[i].ff - p[i].ss);
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    ll ans = max(plus[n-1] - plus[0], minus[n-1] - minus[0]);
    cout << ans << endl;
    return 0;
}