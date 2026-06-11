#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
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
  
  ll n;
  cin >> n;
  vector<ll>plus,minus;
  rep(i,n){
    ll a;
    cin >> a;
    if(0<=a)plus.push_back(a);
    else minus.push_back(a);
  }
  sort(all(plus),greater<ll>());
  sort(all(minus));
  if(minus.empty()) minus.push_back(plus.back()), plus.pop_back();
  if(plus.empty()) plus.push_back(minus.back()), minus.pop_back();
  
  vector<P>ans;
  ll now= minus[0];
  
  rep(i,plus.size()-1){
    ans.push_back(P(now,plus[i]));
    now-=plus[i];
  }
  ans.push_back(P(plus.back(),now));
  now=plus.back()-now;
  
  rep(i,minus.size()-1){
    ans.push_back(P(now,minus[i+1]));
    now-=minus[i+1];
  }
  
  cout << now << endl;
  rep(i,n-1){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  
    
  return 0;     
}
