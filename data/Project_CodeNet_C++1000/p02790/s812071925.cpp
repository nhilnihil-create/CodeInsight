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
  int a, b;
  cin >> a >> b;
  
  rep(i, 0, max(a,b)){
    cout << min(a, b);
  }
  cout << endl;
  
  return 0;
  
}