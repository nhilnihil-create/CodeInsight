//Tsundoku

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
    int n,m,k;cin>>n>>m>>k;
    deque<int>t(n),b(m);
    rep(i,0,n)cin>>t[i];
    rep(i,0,m)cin>>b[i];
    reverse(range(t));
    int s=accumulate(range(t),0LL),ans=0;
    t.pb(0);
    while(true){
        bool flag=false;
        while(s>k){
            if(t.front()==0)flag=true;
            if(flag==true&&t.front()!=0)break;
            s-=t.front();
            t.pop_front();
        }
        if(flag==true&&t.front()!=0)break;
        ans=max(ans,(int)t.size()-1);
        if(b.size()<1)break;
        t.pb(b.front());
        s+=b.front();
        b.pop_front();
    }
    cout<<ans;
    return 0;
}