//01 Matri

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
    int h,w,a,b;cin>>h>>w>>a>>b;
    rep(i,0,h){
        rep(j,0,w){
            if(i<b){
                if(j<a){
                    cout<<0;
                }else{
                    cout<<1;
                }
            }else{
                if(j<a){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
        }
        cout<<nnn;
    }
    return 0;
}