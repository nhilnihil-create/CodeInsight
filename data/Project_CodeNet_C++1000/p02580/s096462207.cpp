//Bomber 

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
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
    int h,w,m;cin>>h>>w>>m;
    vector<int>hs(h,0),ws(w,0);
    set<P>bm;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        a--;b--;
        bm.insert(mp(a,b));
        hs[a]++;
        ws[b]++;
    }
    int hm=*max_element(range(hs)),wm=*max_element(range(ws));
    int ans=hm+wm-1;
    vector<int>hml,wml;
    rep(i,0,h)if(hs[i]==hm)hml.pb(i);
    rep(i,0,w)if(ws[i]==wm)wml.pb(i);
    for(auto i:hml)for(auto j:wml){
        if(bm.count(mp(i,j)))continue;
        else{
            cout<<ans+1<<nnn;
            return 0;
        };
    }
    cout<<ans<<nnn;
    return 0;
}