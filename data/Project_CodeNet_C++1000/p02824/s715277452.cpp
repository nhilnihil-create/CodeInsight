#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  ll n,m,v,p;
  cin >> n >> m >> v >> p;
  vector<ll>a(n);
  rep(i,n) cin >> a[i];
  sort(all(a),greater<ll>());
  int ok=0,ng=n;
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(mid<p)ok=mid;
    else if(a[p-1]>a[mid]+m)ng=mid;
    else {
      ll vote=0;
      vote+=(p-1)*m+(n-mid)*m;
      exrep(i,p-1,mid-1){
        vote+=max(0ll,a[mid]+m-a[i]);
      }
      if(vote>=m*v)ok=mid;
      else ng=mid;
    }
  }
  cout << ok+1 << endl;
  
}
