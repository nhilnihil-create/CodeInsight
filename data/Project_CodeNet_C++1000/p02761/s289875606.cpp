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
const ll N = 5e5 + 1;//                                                             |
//----------------------------------------------------------------------------------



void solve()
{   
    ll n,q;cin>>n>>q;
    ii m,mark;
    int f=0;
    for(int i=0;i<q;i++){
        ll x,y;cin>>x>>y;
        if(mark[x] && m[x]!=y) f=1;
        m[x]=y;
        mark[x]=1;
    }
    if(f) cout<<-1<<"\n";
    else{
        if(n==1) {
            cout<<m[1];
        }
        else{
            if(mark[1] && m[1]==0) cout<<-1<<"\n";
            else{
                for(int i=0;i<n;i++){
                    if(i==0 && !mark[1]) cout<<1;
                    else{
                        if(mark[i+1]){
                            cout<<m[i+1];
                        }
                        else cout<<0;
                    }
                }
            }
        }
    }
}
 
 
int main()
{
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