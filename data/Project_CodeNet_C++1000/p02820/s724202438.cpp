#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  ll score = 0;
  vector<bool> ok(n, true);
  for(int i=0; i<n; i++){
    if(i-k >= 0){
      if(t[i] == t[i-k] && ok[i-k] == false) continue;
    }
    ok[i] = false;
    if(t[i] == 'r') score += p;
    else if(t[i] == 's') score += r;
    else score += s;
  }
  cout << score << endl;
}
