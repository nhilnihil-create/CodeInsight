#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define forn(i,n1, n2) for (ll i = n1; i < n2; i++)
#define w(t) ll t;cin>>t;while(t--)
#define en "\n"
#define f first
#define s second
const ll mod = 1000000007;
using namespace std;
ll i, n, m, x, y, z, j, k, l, mn = LLONG_MAX, mx = 0, c, a[2000005], r, cnt = 0, sum = 0,p;
string str;
char ch;
set<ll> s;
map<ll, ll> mp;
vector<vector<ll>> g;
vector<ll> v;
char grid[60][60];
ll d[60][60];
bool vis[60][60];
ll dx[] = {0, 1, 0, -1, 1, -1, -1, 1};
ll dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
ll gcd(ll a , ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    ll k1,k2,k3,k4,a,b,c,d;
    cin>>a>>b>>c>>d;
    k1=a*c;
    k2=a*d;
    k3=b*d;
    k4=b*c;
    cout<<max(max(k1,k2),max(k3,k4));
 
    return 0;
}