#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n;
  cin >> n;
  vector<int> ans(n+5,0);
  for(int i = 0; i < n-1; i++){
    int a;
    cin >> a;
    ans[a]++;
  }
  for(int i = 1; i <= n; i++){
    cout << ans[i] << endl;
  }
  return 0;
}