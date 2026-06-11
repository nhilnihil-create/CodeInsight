//Megalomania

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define nxvarep(n,x,a) ll n,x;cin>>n>>x;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
#define cout15(a) printf("%.15f\n",a)
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<ll,ll> p;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int main (){
    int n;cin>>n;
    vector<p>a(n);
    rep(i,0,n)cin>>a[i].second>>a[i].first;
    sort(range(a));
    ll c=0,lm=0;
    rep(i,0,n){
        c+=a[i].second;
        if(a[i].first<c){
            cout<<"No"<<nnn;
            return 0;
        }
    }
    cout<<"Yes"<<nnn;
    return 0;
}