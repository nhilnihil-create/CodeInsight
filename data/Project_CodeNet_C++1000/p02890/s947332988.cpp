#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P,vector<P>,greater<P>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double pi=3.14159265358979323846;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
void outvi(vi v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
void outvvi(vvi v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}
int main(){
ll n;cin>>n;
vi v(n);
rep(i,n){
ll k;cin>>k;
v[k-1]++;
}
sort(all(v));
vi rui(n+1);
rui[0]=0;
REP(i,1,n+1)rui[i]=v[i-1]+rui[i-1];
rep(i,n){
ll ok=0,ng=n+1;
while(ng-ok>1){
ll mid=(ok+ng)/2;
ll u=lb(v,mid);
if((i+1)*mid<=(n-u)*mid+rui[u])ok=mid;
else ng=mid;
}
cout<<ok<<endl;
}
}