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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
  }
  int l=0, r=1e9;
  while(l+1<r){
    int x=(r+l)/2;
    ll now=0;
    rep(i, n){
      now+=(a[i]-1)/x;
    }
    if(now<=k){
      r=x;
    } else {
      l=x;
    }
  }
  cout << r << endl;
  return 0;
}
