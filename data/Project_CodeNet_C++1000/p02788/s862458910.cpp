#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll> ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <vector <vector<ll> > > vvv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define tr1(x) cerr << #x << ": " << x << endl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define tr4(x,y,z,w) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#w<<": "<<w<<endl
#define trv(a) cerr<<#a<<": ";for(ll zz=0;zz<a.size();zz++) cerr<<a[zz]<<" ";cerr<<endl
#define trset(s) cerr<<#s<<": ";for(auto &i:s) cerr<<i<<" ";cerr<<"\n"
#define mod 1000000007ll
#define inf 9999999999999999ll
#define nl endl
#define modulo 998244353



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,d,a;
    cin>>n>>d>>a;
    vi x(n),h(n);
    vii q(n);
    for(ll i=0;i<n;i++)
        cin>>q[i].F>>q[i].S;
    sort(q.begin(),q.end());
    for(ll i=0;i<n;i++)
    {
        x[i]=q[i].F;
        h[i]=q[i].S;
    }
    set <ii> s;
    ll sum=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        while(!s.empty() && (s.begin()->F)<x[i])
        {
            sum-=s.begin()->S;
            s.erase(s.begin());
        }
        if(sum<h[i])
        {
            ll extra=h[i]-sum;
            ll bombs=(extra+a-1)/a;//i.e    ceil(extra)/a
            sum+=bombs*a;
            ans+=bombs;
            s.insert(mp(x[i]+2*d,bombs*a));
        }
    }
    cout<<ans<<nl;
}
