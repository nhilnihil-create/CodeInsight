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
    vl v(n);
    for(auto &i:v) cin>>i;
    ll k=v[n-1];
    k*=2;
    for(int i=0;i<n-1;i++){
        k=v[i]*2-k;
    }
    k=abs(k);
    k/=4;
    
    vl ans(n);
    ans[n-1]=k*2;
    for(int i=n-2;i>=0;i--){
        ans[i]=(v[i]-k)*2;
        k=(v[i]-k);
    }
    for(auto i:ans) cout<<i<<" ";
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