#include <bits/stdc++.h>
using namespace std;
 

 
 
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
const ll N = 1e5 + 1;//                                                             |
//----------------------------------------------------------------------------------


void solve()
{   
    ll n;cin>>n;
    multiset<ld> m;
    for(int i=0;i<n;i++){
        ld k;cin>>k;
        m.pb(k);
    }
    while(m.size()>1){
        ld a=*m.begin();
        m.erase(m.begin());
        a+=*m.begin();
        m.erase(m.begin());
        m.pb(a/2.0);
    }
    cout<<*m.begin()<<"\n";
    
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