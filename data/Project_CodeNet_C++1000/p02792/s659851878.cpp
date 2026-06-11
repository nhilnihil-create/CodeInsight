//Handstand 2

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

signed main (){
    int n;cin>>n;
    vector<vector<int>>c(10,vector<int>(10,0));
    rep(i,1,n+1){
        string s = to_string(i);
        int a,b;
        a=s[0]-'0';b=s[s.size()-1]-'0';
        c[a][b]++;
    }
    int ans = 0;
    rep(i,1,10){
        rep(j,1,10){
            ans+=c[i][j]*c[j][i];
        }
    }
    cout<<ans<<nnn;
    return 0;
}