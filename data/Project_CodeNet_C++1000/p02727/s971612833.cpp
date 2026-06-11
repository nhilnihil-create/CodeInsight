//

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
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
    priority_queue<int,vector<int>,greater<int>>p,q;
    priority_queue<int>r;
    rep(i,0,a){
        int t;cin>>t;
        p.push(t);
    }
    rep(i,0,b){
        int t;cin>>t;
        q.push(t);
    }
    rep(i,0,c){
        int t;cin>>t;
        r.push(t);
    }
    while(p.size()>x)p.pop();
    while(q.size()>y)q.pop();
    rep(i,0,c){
        int j=p.top(),k=q.top(),l=r.top();
        if(j<=k&&j<l){
            p.pop();
            r.pop();
            p.push(l);
        }else if(k<=j&&k<l){
            q.pop();
            r.pop();
            q.push(l);
        }else{
            break;
        }
    }
    int ans = 0;
    while(!p.empty()){ans+=p.top();p.pop();}
    while(!q.empty()){ans+=q.top();q.pop();}
    cout<<ans<<nnn;
}