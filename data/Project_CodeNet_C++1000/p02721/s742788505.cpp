#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define eb emplace_back
//#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 1e6 + 69;
const int base = 311;


// dung inverse module de tinh nCk
// beginer 87
// mbeginer 161
// cach tao hoan vi tu n so : n*(n+1)/2;

//vector<pair<ll,ll>>adj[e];
//vector<ll>adj[e];

/*ll Pow(ll n, ll dem)
{
    if(dem == 0) return 1;
    if(dem == 1) return n ;
    ll t = Pow(n, dem/2);
    if(dem % 2 == 0) return (t*t);
    else return ((t * t) * n);
}*/

/*ll C(ll k, ll n)
{
    if(k == 0) return 1;
    if(n < k) return 0;
    return (gt[n]%mod * (igt[k]%mod * igt[n-k]%mod)%mod)%mod;
}*/

int main()
{
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    //s = ' ' + s;
    vector<ll>lf, rg;
    ll can = 1e18;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'o' && can >= c) lf.pb(i), can = 0;
        else can ++;
        if(lf.size() == k) break;
    }
    can = 1e18;
    for(int i=n-1; i>=0; i--)
    {
        if(s[i] == 'o' && can >= c) rg.pb(i), can = 0;
        else can ++;
        if(rg.size() == k) break;
    }
    reverse(rg.begin(), rg.end());
    for(int i=0; i<k; i++)
    {
        if(lf[i] == rg[i]) cout << lf[i] + 1 <<"\n";
    }
    //cout << ans;
}
/*

*/
