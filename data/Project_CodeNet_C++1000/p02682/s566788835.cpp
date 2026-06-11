#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  //aが1 bが0 cが-1
  int ans = 0;
  for(int i = 0; i < k; i++){
    if(a > 0){
      ans++;
      a--;
    }else if(b > 0){
      ans += 0;
      b--;
    }else if(c > 0){
      ans -= 1;
      c--;
    }
  }
  cout << ans << endl;



}
