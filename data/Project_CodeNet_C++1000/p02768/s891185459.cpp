#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
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

//fast_exponential function
ll fast_exp(ll x, ll y, ll m){
    ll res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=m;
        }
        x*=x;
        x%=m;
        y>>=1;
    }
    return res;
}


//solution
void solve()
{   
    ll a,b,c;cin>>a>>b>>c;
    vl fact(N,0),r_fact(N,0);
    fact[0]=a;
    r_fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=fact[i-1]*(a-i);
        fact[i]%=mod;
        r_fact[i]=r_fact[i-1]*(i+1);
        r_fact[i]%=mod;
    }
    ll ans=fast_exp(2,a,mod)-1; // this part was most beautiful , damn what a sexy problem it was *_*
    if(b<=a){
        ans-=fact[b-1]*fast_exp(r_fact[b-1],mod-2,mod);
        while(ans<0)
        ans+=mod;
        ans%=mod;
    }
    if(c<=a){
        ans-=fact[c-1]*fast_exp(r_fact[c-1],mod-2,mod);
        while(ans<0)
        ans+=mod;
        ans%=mod;
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