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

void re(ll &cnt, vector<bool> used, vvl &per, ll dps){
  ll n = used.size()-1;
  rep(i, 0, n+1){
    if(used[i] == false)
      break;
    else if(i == n){
      cnt++;
      per[cnt] = per[cnt-1];
      return;
    }
  }
  
  rep(i, 1, n+1){
    if(used[i] == false){
      vector<bool> used_new = used;
      used_new[i] = true;
      per[cnt][dps] = i;
      re(cnt, used_new, per, dps+1);
    }
  }
}

int main(){
  ll n;
  cin >> n;
  vl p(n), q(n);
  rep(i, 0, n)
    cin >> p[i];
  rep(i, 0, n)
    cin >> q[i];
  
  vvl per(50000, vl(n,0));
  vector<bool> used(n+1, false);
  used[0] = true;
  ll cnt = 0;
  
  re(cnt, used, per, 0);
  
  ll a = 0, b = 0;
  
  rep(i, 0, 50000){
    if(per[i][0] == 0)
      continue;
    if(per[i] < p)
      a++;
    if(per[i] < q)
      b++;
  }
  
  cout << abs(a-b) << endl;
  
  return 0;
  
}