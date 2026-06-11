#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n, ans=0;
  ll d;
  cin >> n >> d;
  ll dd=d*d;

  rep(i, n){
    ll x, y;
    cin >> x >> y;
    ll xx=x*x, yy=y*y;
    if(xx+yy<=dd){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
