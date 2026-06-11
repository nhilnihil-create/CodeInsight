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
  ll a;
  double b;
  cin >> a >> b;
  double b2=b*100+0.5;
  ll ans=a*(int)b2;
  ans/=10ll;
  ans/=10ll;
  cout << ans << endl;
  return 0;
}
