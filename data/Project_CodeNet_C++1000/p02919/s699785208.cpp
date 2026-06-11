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
const int Inf=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
int main(){
    int n;cin>>n;
    ll ans=0;
    vi v(n);
    rep(i,n){
        int a;cin>>a;
        v[n-a]=i;
    }
    S s;
    rep(i,2){s.insert(-1);s.insert(n);}
    rep(i,n){
        auto it=s.lower_bound(v[i]);
        it++;
        vi x(4);
        rep(j,4){
            x[3-j]=*it;
            it--;
        }
        ans+=(n-i)*((x[1]-x[0])*(x[2]-v[i])+(v[i]-x[1])*(x[3]-x[2]));
      s.insert(v[i]);
    }
    cout<<ans<<endl;
}