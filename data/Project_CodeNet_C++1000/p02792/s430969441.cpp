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
  ll c[10][10];
  rep(i, 0, 10){
    rep(j, 0, 10){
     c[i][j] = 0;
    }
  }
  
  rep(i, 0, n+1){
    char f, e;
    string s = to_string(i);
    f = s[0];
    e = s[s.size() - 1];
    int a, b;
    a = f-'0';
    b = e-'0';
    c[a][b]++;
  }
  
  ll sum = 0;
  
  rep(i, 1, 10){
    rep(j, i, 10){
      if(i == j)
        sum += (c[i][j]*c[i][j]);
      else
        sum += c[i][j]*c[j][i]*2;
    }
  }
  cout << sum << endl;
  
  return 0;
  
}