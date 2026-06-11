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

string s;
ll n=2e5+1;
ll dp[N][13];

ll check(ll x, ll y){
    if(x==n && y==5){
        
        return 1;
    }
    ll k=0;
    
    if(s[x]=='?'){
        for(ll i=0;i<10;i++){
            ll tmp=y*10;
            tmp+=i;
            tmp%=13;
            if(dp[x+1][tmp]!=-1){
                k+=dp[x+1][tmp];
            }
            else k+=check(x+1,tmp);
            k%=mod;
        }
    }
    else if(x!=n){
        ll tmp=y*10;
        ll z=(s[x]-'0');
        tmp+=z;
        tmp%=13;
        if(dp[x+1][tmp]!=-1){
            k+=dp[x+1][tmp];
        }
        else k+=check(x+1,tmp);
    }
    
    dp[x][y]=k%mod;
    return k%mod;
}

void solve()
{   
    cin>>s;
    n=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<check(0,0);
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