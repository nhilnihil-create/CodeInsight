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
using vvi=vector<vi>;
using vvvi=vector<vvi>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double pi=3.14159265358979323846;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<endl;}
template<class T> void outvp(T v){rep(i,v.size())outp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
template<class T> void outvv(T v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}
int main(){
    ll n,m,a,b,c,d;cin>>n>>m>>a>>b>>c>>d;
    ll i=(a-c)*n,j=(b-d)*m;
    if(i+j==0)out("infinity");
  	else if(i>0&&i+j>0)out(0);
    else if(i<0&&i+j<0)out(0);
    else{
        ll ans=((abs(i)/abs(i+j))+1)*2;
        if(((abs(i))%(abs(i+j)))==0)ans--;
        out(ans-1);
    }
}
