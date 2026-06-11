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
  int n, m;
  cin >> n >> m;
  vector<bool> check(n, false);
  vi cnt(n, 0);
  
  rep(i, 0, m){
    int p;
    string s;
    cin >> p >> s;
    p--;
    if(s == "WA"){
      if(check[p] == false)
        cnt[p]++;
    }
    else if(s == "AC")
      check[p] = true;
  }
  
  int ac = 0;
  int wa = 0;
  
  rep(i, 0, n){
    if(check[i]){
      ac++;
      wa += cnt[i];
    }
  }
  
  cout << ac << " " << wa << endl;
  
  return 0;
  
}