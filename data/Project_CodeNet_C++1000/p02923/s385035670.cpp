#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi h(n);
  rep(i,n) cin >> h[i];
  int ans = 0;
  int cnt = 0;
  rep(i,n-1){
    if(h[i] >= h[i+1]) cnt++;
    else{
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);
  cout << ans << endl;
}
