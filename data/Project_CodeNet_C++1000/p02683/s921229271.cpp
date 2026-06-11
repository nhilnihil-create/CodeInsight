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
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  int a[15][15];
  rep(i, n){
    cin >> c[i];
    rep(j, m){
      cin >> a[i][j];
    }
  }
  int ans=INF;
  for(int i=0; i<(1<<n); i++){
    int cost=0;
    vector<int> und(m);
    rep(j, n){
      if(i &(1<<j)){
        cost+=c[j];
        rep(k, m){
          und[k]+=a[j][k];
        }
      }
    }
    bool flag=true;
    rep(k, m){
      if(und[k]<x){
        flag=false;
        break;
      }
    }
    if(flag){
      ans=min(ans, cost);
    }
  }
  if(ans==INF){
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
