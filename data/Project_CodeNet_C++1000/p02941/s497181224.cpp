#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
int main(){
    ll n,ans=0;cin>>n;
    vi a(n),b(n);
    rep(i,n)cin>>a[i];
    priority_queue<P> p;
    rep(i,n){
        cin>>b[i];
        if(b[i]<a[i]){
            cout<<-1<<endl;
            return 0;
        }
        if(b[i]==a[i])continue;
        p.push(P(b[i],i));
    }
    while(!p.empty()){
        auto d=p.top();p.pop();
        ll i=d.second;
        ll x=b[i],y=b[(n+i-1)%n]+b[(i+1)%n];
        if(x%y>=a[i]){
            if(x/y==0){
                cout<<-1<<endl;
                return 0;
            }
            ans+=x/y;
            b[i]=x%y;
        }
        if(x%y>a[i])p.push(P(b[i],i));
        if(x%y<a[i]){
            if((x-a[i])/y==0){
                cout<<-1<<endl;
                return 0;
            }
            ans+=(x-a[i])/y;
            b[i]=a[i]+(x-a[i])%y;
            if(b[i]!=a[i])p.push(P(b[i],i));
        }
    }
    cout<<ans<<endl;
}