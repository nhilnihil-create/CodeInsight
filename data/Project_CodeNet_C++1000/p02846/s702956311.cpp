#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  a1 *= t1;
  a2 *= t2;
  b1 *= t1;
  b2 *= t2;
  a2 += a1;
  b2 += b1;
  if(a2 == b2){
    cout << "infinity" << endl;
    return 0;
  }
  if(a2 < b2){
    swap(a1,b1);
    swap(a2,b2);
  }
  int c = b1 - a1;
  int d = a2 - b2;
  int ans = 0;
  if(c > 0){
    ans = (c-1)/d + 1;
    ans *= 2;
    ans--;
    if(c % d == 0) ans++;
  }
  cout << ans << endl;
}