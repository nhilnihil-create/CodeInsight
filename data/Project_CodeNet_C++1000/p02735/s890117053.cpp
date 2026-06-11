//Range Flip Find Route

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
    int h,w;cin>>h>>w;
    vecrep(h,s,string);
    vector<vector<int>>ans(h,vector<int>(w,0));
    if(s[0][0]=='#')ans[0][0]=1;
    rep(i,1,h){
        if(s[i-1][0]!=s[i][0]&&s[i][0]=='#')ans[i][0]=ans[i-1][0]+1;
        else ans[i][0]=ans[i-1][0];
    }
    rep(i,1,w){
        if(s[0][i-1]!=s[0][i]&&s[0][i]=='#')ans[0][i]=ans[0][i-1]+1;
        else ans[0][i]=ans[0][i-1];
    }
    rep(i,1,h){
        rep(j,1,w){
            int ue = ans[i-1][j] + (s[i-1][j]!=s[i][j]&&s[i][j]=='#'?1:0);
            int hd = ans[i][j-1] + (s[i][j-1]!=s[i][j]&&s[i][j]=='#'?1:0);
            ans[i][j] = min(ue,hd);
        }
    }
    cout<<ans[h-1][w-1]<<nnn;
    return 0;
}