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
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, n){
    cin >> h[i];
  }
  vector<vector<int> > to(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  int ans=0;
  rep(i, n){
    int siz=to[i].size();
    bool good=true;
    rep(j, siz){
      if(h[i]<=h[to[i][j]]){
        good=false;
        break;
      }
    }
    if(good){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
