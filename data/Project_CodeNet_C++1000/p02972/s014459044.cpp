//Preparing Boxes

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
using p = pair<ll, string>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    nvarep(n,a);
    vector<int>ans(n,0);
    int s=0;
    for(int i=n;i>0;i--){
        int c=0,j=1;
        for(;i*j<=n;j++){
            c+=ans[i*j-1];
        }
        if(c%2!=a[i-1])ans[i-1]++,s++;
    }
    cout<<s<<nnn;
    rep(i,0,n)if(ans[i]==1)cout<<i+1<<nnn;
    return 0;
}