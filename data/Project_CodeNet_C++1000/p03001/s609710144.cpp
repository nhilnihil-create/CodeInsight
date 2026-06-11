#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  
  long double w,h,x,y;
  cin >> w >> h >> x >> y;
  if(w/2==x && h/2==y){
    cout << fixed << setprecision(9) << w*h/2 << endl;
    cout << 1 << endl;
  }
  else{
    cout << fixed << setprecision(9) << w*h/2 << endl;
    cout << 0 << endl;
  }
  return 0;
}
