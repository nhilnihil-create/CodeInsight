//Face Produces Unhappiness

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
    int n,k;string s;cin>>n>>k>>s;
    int t=0,h=0;
    rep(i,0,n){
        if(i==0){if(s[i]=='R'&&s[i+1]=='L')t++;else if(s[i]=='L')h++;}
        else if(i==n-1){if(s[i]=='L'&&s[i-1]=='R')t++;else if(s[i]=='R')h++;}
        else if(s[i]=='R'&&s[i+1]=='L')t++;
        else if(s[i]=='L'&&s[i-1]=='R')t++;
    }
    rep(i,0,k){
        if(t>0)t-=2;
        else if(h>1)h--;
        else break;
    }
    if(h==0&&t==0)h++;
    cout<<n-t-h<<nnn;
    return 0;
}