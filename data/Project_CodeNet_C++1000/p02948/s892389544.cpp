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
const ll N = 1e6 + 1;//                                                             |
//----------------------------------------------------------------------------------


void solve()
{   
    ll x,y;cin>>x>>y;
    multiset<pp> m;
    sl s;
    for(int i=0;i<x;i++){
        ll a,b;cin>>a>>b;
        m.pb({b,a});
    }
    for(ll i=0;i<y;i++){
    	s.pb(-1*i);
    }
    ll ans=0;
    ll i=0;
    while(!m.empty()){
        ll a=(*--m.end()).ff,b=(*--m.end()).ss;
        ll k=y-b;
        k*=-1;
        auto it=s.lower_bound(k);
        if(it!=s.end()){
        	s.erase(it);
        	ans+=a;
        }
        m.erase(--m.end());
    }
    cout<<ans<<"\n";
}
 
int main()
{	
	#ifndef ONLINE_JUDGE 
   		freopen("input.txt", "r", stdin);  
   		freopen("output.txt", "w", stdout); 
   	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
     

    ll t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    
	return 0;
}