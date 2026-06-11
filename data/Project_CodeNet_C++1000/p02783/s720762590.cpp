#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

int main(){
  int h, a;
  cin >> h >> a;
  
  int ans = 0;
  
  while(h > 0){
    h -= a;
    ans ++;
  }
  
  cout << ans << endl;
  
  return 0;
  
}