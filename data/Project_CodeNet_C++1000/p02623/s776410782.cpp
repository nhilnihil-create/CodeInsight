#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(ll i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int ll;
typedef unsigned long long int ull; 
typedef pair<ll,ll> Pi;
typedef tuple<ll,ll,ll> Tu;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const double PI=3.14151926535;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
const ll tMOD=(ll)998244353;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[8]={0,1,0,-1,1,1,-1,-1},mdy[8]={-1,0,1,0,1,-1,1,-1};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


ll n,m,k;
ll a[200100],b[200100];

int main(){
  cin>>n>>m>>k;
  FOR(i,1,n+1)cin>>a[i];
  FOR(i,2,n+1)a[i]+=a[i-1];
  FOR(i,1,m+1)cin>>b[i];
  FOR(i,2,m+1)b[i]+=b[i-1];
  int ans=0;
  for(int i=0;i<=n;i++){
    if(a[i]>k)break;
    ll t=k-a[i];
    int seab=upper_bound(b,b+m+1,t)-b-1;
    ans=max(ans,seab+i);
  }
  cout<<ans<<endl;
}