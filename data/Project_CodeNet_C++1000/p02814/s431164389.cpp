#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pii pair <int,int>
#define pll pair <ll,ll>
#define testcase() int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define vll vector <ll>
#define vi vector <int>
#define all(v) v.begin(),v.end()

ll M = 1e9 + 7;
double pi = acos(-1.0);
ll powerm(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x)%M; y=y>>1; x=(x*x)%M;} return res%M; }
ll power(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x); y=y>>1; x=(x*x);} return res; }
ll gcd(ll a,ll b){if(b>a)return gcd(b,a); if(b==0)return a; return gcd(b,a%b);}

int main() {
	
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	int n; ll m; cin>>n>>m;
    ll g = 1;
    vll a(n); bool ok=1;
    forn(i,n)
    {
        cin>>a[i];
        if(a[i]&1) ok=0;
        ll h = a[i]/2;
        if(g<0){ cout<<0; return 0; }
        g = (g*h)/gcd(g,h);
    }
    if(!ok){ cout<<0; return 0; }
    forn(i,n)
    {
        ll h = g/(a[i]/2);
        if(~h&1){ ok=0; break; }
    }
    if(!ok) cout<<0;
    else
    {
        ll f = m/g;
        cout<<(f+1)/2;
    }
    

	return 0;
}
