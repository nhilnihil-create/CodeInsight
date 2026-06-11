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

signed main(){
  int t,tt,a,aa,b,bb;cin>>t>>tt>>a>>aa>>b>>bb;
  if(a > b){
    a -= b;aa -= bb;
  }else{
    a = b - a, aa = bb - aa;
  }
  int p = t*a, q = tt*aa;
  if(p+q == 0){
    cout << "infinity" << endl;return 0;
  }else if(p+q > 0){
    cout << 0 << endl;return 0;
  }else if(q % (p+q) == 0){
    cout << (q/(p+q)-1)*2 << endl;
  }else{
    cout << (q/(p+q)-1)*2+1 << endl;
  }
}
