//Lucky PIN

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
    int n;
    string s;
    cin>>n>>s;
    int ans{};
    bool flag=false;
    rep(i,0,10)rep(j,0,10)rep(k,0,10){
        flag=false;
        for(int q=0;q<n;q++){
            if(flag)break;
            if(s[q]-'0'==i){
                for(q++;q<n;q++){
                    if(flag)break;
                    if(s[q]-'0'==j){
                        for(q++;q<n;q++){
                            if(flag)break;
                            if(s[q]-'0'==k){
                                ans++;flag=true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<nnn;
    return 0;
}