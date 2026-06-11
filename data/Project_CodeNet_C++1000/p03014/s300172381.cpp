//Lamp 

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
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

vector<string> pictureframe(vector<string> md,char fm){
    int w=md[0].size();
    int h=md.size();
    string s(w+2,fm);
    vector<string>picfm(h+2,s);
    rep(i,1,h+1)rep(j,1,w+1)picfm[i][j]=md[i-1][j-1];
    return picfm;
}

signed main (){
    int h,w,ans=0;cin>>h>>w;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    s=pictureframe(s,'#');
    vector<vector<int>>r(h+2,vector<int>(w+2,0))
                      ,l(h+2,vector<int>(w+2,0))
                      ,u(h+2,vector<int>(w+2,0))
                      ,d(h+2,vector<int>(w+2,0));
    rep(i,1,h+1)rep(j,1,w+1){
        if(s[i][j]=='.')l[i][j]=l[i][j-1]+1;
        if(s[i][j]=='.')u[i][j]=u[i-1][j]+1;
    }
    for(int i=h;i>=1;i--)for(int j=w;j>=1;j--){
        if(s[i][j]=='.')r[i][j]=r[i][j+1]+1;
        if(s[i][j]=='.')d[i][j]=d[i+1][j]+1;
    }
    rep(i,1,h+1)rep(j,1,w+1)ans=max(ans,l[i][j]+r[i][j]+d[i][j]+u[i][j]-3);
    cout<<ans<<nnn;
    return 0;
}