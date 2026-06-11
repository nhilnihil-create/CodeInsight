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
  
  int n,m;
  cin >> n >> m;
  vector<P>vec;
  if(n%2){
    for(int l=1,r=n-1;l<=n/2;l++,r--){
      vec.push_back(P(l,r));
    }
  }
  else{
    int l=1,r=n,cnt=1;
    while(cnt<=n/4){
      vec.push_back(P(l,r));
      l++;
      r--;
      cnt++;
    }
    l++;
    while(abs(l-r)>1){
      vec.push_back(P(l,r));
      l++;
      r--;
    }
  }
  rep(i,m){
    cout << vec[i].first << " " <<vec[i].second << endl;
  }
  return 0;     
}
