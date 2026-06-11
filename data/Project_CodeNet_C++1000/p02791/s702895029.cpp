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
  int n;
  cin >> n;
  vi p(n);
  rep(i, 0, n)
    cin >> p[i];
  
  int cnt = 0;
  int mn = p[0];
  
  rep(i, 0, n){
    if(mn >= p[i]){
      cnt++;
      mn = p[i];
    }
  }
  
  cout << cnt << endl;
  
  return 0;
  
}