#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<pair<int,int>> a;

  for(int i = 1;i<=n;i++){
    int cnt;
    cin >> cnt;
    a.emplace_back(cnt,i);
  }
  sort(a.begin(),a.end());

  for(auto x : a){
    int ans = x.second;
    cout << ans << " ";
  }
  cout << endl;
  
  return 0;
}
