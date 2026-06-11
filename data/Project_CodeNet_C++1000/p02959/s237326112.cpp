#include <bits/stdc++.h>
using namespace std;
 
//krishrawat
 
 
//----------------------------MACROS-------------------------------------------------
#define pb insert//                                                                 |
#define eb emplace_back//                                                           |
#define ff first//                                                                  |
#define ss second//                                                                 |
typedef long long int ll;//                                                         |
typedef long double ld;//                                                           |
#define all(a) a.begin(), a.end()//                                                 |
#define show(x) cerr << #x << " is " << x << "\n"//                                 |
#define show2(x, y) cerr << #x << " " << #y << " " << x << " " << y << "\n"//       |
typedef vector<ll> vl;//                                                            |
typedef vector<vl> vvl;//                                                           |
typedef pair<ll, ll> pp;//                                                          |
typedef vector<pp> vp;//                                                            |
typedef map<pp, ll> ipi;//                                                          |
typedef map<pp, char> ipc;//                                                        |
typedef map<ll, ll> ii;//                                                           |
typedef set<ll> sl;//                                                               |
typedef multiset<ll> msl;//                                                         |
typedef map<char, ll> ci;//                                                         |
typedef set<pair<ll, ll>> sp;//                                                     |
const ll mod = 1e9 + 7;//                                                           |
const ll N = 2e5 + 1;//                                                             |
//----------------------------------------------------------------------------------



void solve()
{   
    ll n;cin>>n;
    vl v(n+1);
    vl m(n);
    for(auto &i:v) cin>>i;
    for(auto &i:m) cin>>i;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll k=min(m[i],v[i]);
        v[i]=0;
        m[i]-=k;
        ll w=min(m[i],v[i+1]);
        v[i+1]-=w;
        ans+=k+w;
    }
    cout<<ans<<"\n";
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll t; t=1;
    //cin>>t;
    while(t--) solve(); return 0;
}