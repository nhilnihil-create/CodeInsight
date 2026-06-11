//HonestOrUnkind2

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
using p = pair<ll, map<int,int>>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n;cin>>n;
    vector<p>m(n);
    rep(i,0,n){
        int a;cin>>a;
        m[i].first=i;
        rep(j,0,a){
            int t,y;cin>>t>>y;
            m[i].second[t-1]=y;
        }
    }
    int ans=0;
    rep(bit,0,(1<<n)){
        vector<int>c(n,-1);
        int sho=0;
        bool mujun=true;
        rep(i,0,n)if(bit&(1<<i)){
            c[i]=1;
            sho++;
        }else c[i]=0;
        rep(i,0,n)if(bit&(1<<i))for(auto j:m[i].second)if((j.second==0&&c[j.first]==1)||(j.second==1&&c[j.first]==0))mujun=false;
        if(mujun)ans=max(ans,sho);
    }
    cout<<ans<<nnn;
    return 0;
}