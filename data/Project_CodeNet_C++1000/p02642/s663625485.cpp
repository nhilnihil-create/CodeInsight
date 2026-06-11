#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define all(a) begin(a),end(a)
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define sz(x) ((int)x.size())
#define ins insert
#define rep(i,l,u) for(int i=l;i<=u;++i)
#define reb(i,l,u) for(int i=l;i>=u;--i)
using namespace std;
const int maxn=2e5+10;
const int mod=1e9+7;
const int inf=1e18;
int a[maxn];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    map<int,int>vis;
    map<int,int>num;
    int ans=0;
    for(int i=1;i<=n;++i){
        num[a[i]]++;
    }
    for(int i=1;i<=n;++i){
        if(!vis[a[i]]){
            if(num[a[i]]==1)
                ans++;
            for(int j=1;a[i]*j<=1000000;++j){
                vis[a[i]*j]=1;
            }
        }
    }
    cout<<ans<<endl;
}
