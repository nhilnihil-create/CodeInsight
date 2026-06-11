#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int> > 
#define vl vector<long long>
#define vpi vector<pair<int,int> >
#define ll long long 
#define sz(a) int(a.size())
#define forn(i,n) for(int i = 0 ; i < int(n) ; i++)
#define all(x) x.begin(),x.end()
#define vpl vector<pair<long long,long long> > 
#define F first
#define S second
#define mp make_pair
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pci pair<char,int>
#define len(s) s.length()
#define un unsigned
# define M_PI           3.14159265358979323846  /* pi */
#define modulo 998244353ll
#define mod 1000000007ll
#define MAXN  1000001 
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}




void solve()
{
    vi a(3,0);
    forn(i,3)
    cin>>a[i];
    sort(all(a));
    cout<<a[0]+a[1]<<endl;
}


int main()
{
    fast();
    int t;
    // cin>>t;
    t = 1;
    while(t--)
    solve();
    return 0;
}