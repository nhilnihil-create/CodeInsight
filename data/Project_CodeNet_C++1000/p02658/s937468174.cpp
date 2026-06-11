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
  int n;
  cin >> n;
  vector<ull> a(n);
  ull ans=1, MX=1e18;
  rep(i, n){
    cin >> a[i];
    if(a[i]==0){
      cout << "0" << endl;
      return 0;
    }
  }
  rep(i, n){
    if(ans>MX/a[i] || ans*a[i]>MX){
      cout << "-1" << endl;
      return 0;
    } else{
      ans*=a[i];
    }
  }
  cout << ans << endl;
  return 0;
}
