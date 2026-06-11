//Teleporter 

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
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    rep(i,0,n){
        int t;cin>>t;
        a[i]=t-1;
    }
    map<int,int>m{};
    int g=a[0],kai=0;
    m[0]++;
    vector<int>ni;
    while(m[g]<2){
        kai++;
        if(kai==k){
            cout<<g+1<<nnn;
            return 0;
        }
        m[g]++;
        if(m[g]==2)ni.pb(g);
        g=a[g];
    }
    int c=0,o=0;
    for(auto i:m){
        if(i.second==2)c++;
        else if(i.second==1)o++;    
    }
    k-=o;k%=c;
    cout<<ni[k]+1<<nnn;
    return 0;
}