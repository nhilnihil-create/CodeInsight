//Colorful Hats 2

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int mod=1000000007;
    nvarep(n,a);
    vector<deque<int>>t(3,{-1});
    int ans=1;
    rep(i,0,n){
        int c=0;
        rep(j,0,3)if(t[j].back()+1==a[i])c++;
        ans=(ans*c)%mod;
        rep(j,0,3){
            if(t[j].back()+1==a[i]){
                t[j].pb(a[i]);
                break;
            }
        }
    }
    cout<<ans<<nnn;
    return 0;
}