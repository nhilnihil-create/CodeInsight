#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n;
  cin >> n;
  vector<int> ans(n+1);
  rep(i,n) {
    int a;
    cin >> a;
    ans[a] = i+1;
  }
  for(int i = 1; i <= n; i++){
    cout << ans[i] << " ";
    if(i == n) cout << endl;
  }
  return 0;
}