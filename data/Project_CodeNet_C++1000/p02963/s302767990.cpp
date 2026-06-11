#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<long long,long long>;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

  
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  ll s;
  cin >> s;
  ll x2,y2,x3,y3;
  ll M=1000000000;
  y3=M;
  y2=1;
  x3=(M-s%M)%M;
  x2=(s+x3)/M;
  
  cout << 0 << " "  << 0 << "  " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}
