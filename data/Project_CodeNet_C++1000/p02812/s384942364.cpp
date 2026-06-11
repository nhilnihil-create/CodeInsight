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
  string s;
  cin >> n >> s;
  int cnt = 0;
  
  rep(i, 0, n-2){
    if(s[i] == 'A')
      if(s[i+1] == 'B' && s[i+2] == 'C')
        cnt++;
  }
  
  cout << cnt << endl;
  
  return 0;
  
}