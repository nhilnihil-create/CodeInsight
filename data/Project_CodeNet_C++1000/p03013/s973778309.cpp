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
const ll N = 2e6 + 1;//                                                             |
//----------------------------------------------------------------------------------




//main func
void solve()
{
       
    ll a,b;cin>>a>>b;
    vl cnt(a+1,0);
    ii m;
    for(int i=0;i<b;i++){
        ll k;cin>>k;
        m[k]=1;
    }
    
    cnt[0]=1;
    if(!m[1])
    cnt[1]=1;
    for(int i=2;i<=a;i++){
        if(!m[i])
        cnt[i]=(cnt[i-1]+cnt[i-2])%mod;
        //show2(cnt[i],i);
    }
    cout<<cnt[a]<<"\n";
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
