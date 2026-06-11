#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,m,v,vv,p,a[110000];

bool f(int x){
  if(x <= p)return true;
  if(a[x]+m < a[p])return false;
  int k = p*m;
  repd(i,x+1,n+1){
    k += m;
  }
  repd(i,p,x){
    k += (a[x]+m-a[i]);
  }
  return (k >= m*v);
}

signed main(){
  cin>>n>>m>>v>>p;rep(i,n)cin>>a[i+1];a[0] = INF;
  sort(a+1, a+n+1, greater<int>());
  int ok = 1, ng = n+1;
  while(abs(ok-ng) > 1){
    int mid = (ok+ng)/2;
    (f(mid) ? ok : ng) = mid;
  }

  cout << ok << endl;
}


