//Kleene Inversion

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,k;cin>>n>>k;
    vecrep(n,a,int);
    int ans = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(i==j)continue;
            if(a[j]<a[i]){
                if(i<j){
                    ans=(ans+k*(1+k)/2)%1000000007;
                }else{
                    ans=(ans+(k-1)*(1+(k-1))/2)%1000000007; 
                }
            }
        }
    }
    cout<<ans<<nnn;
    return 0;
}