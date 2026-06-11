#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> H(n);
  rep(i,n) cin >> H[i];
  vector<vector<int>> X(n,vector<int>(0));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    X[a].push_back(b);
    X[b].push_back(a);
  }
  int tot = 0;
  rep(i,n){
    bool ans = true;
    for(const auto&it:X[i]){
      if(H[i]<=H[it])ans = false;
    }
    if(ans) tot++;
  }
  cout << tot << endl;

}
