#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,t[60];string s[60];
signed main(){
  cin>>n;
  rep(i,n)cin>>s[i]>>t[i];
  string ss;cin>>ss;
  int ans = 0;bool b = false;
  rep(i,n){
    if(b)ans += t[i];
    if(s[i] == ss)b = true;
  }
  cout << ans << endl;
}

