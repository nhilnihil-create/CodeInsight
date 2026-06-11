#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;


//　一文字のとき
int main() {
  string s; ll k;
  cin >> s >> k;
  if(s.size() == 1){
    cout << k/2 << endl;
    return 0;
  }
  ll l = 1, r = 1;
  rep(i, 1, s.size()){
    if(s[i] == s[i-1]) l++;
    else break;
  }
  for(int i = s.size()-2; i >= 0; i--){
    if(s[i] == s[i+1]) r++;
    else break;
  }
  vector<bool> f(105, true);
  ll cnt = 0;
  rep(i, 0, s.size()){
    if(s[i] == s[i-1] && f[i-1]){
      cnt++;
      f[i] = false;
    }
  }

  ll ans = cnt * k;
  bool g = false;

  rep(i, 1, s.size()) if(s[i] != s[0]) g = true;
  if(!g && s.size()%2 != 0){ // 全部同じ文字　文字の長さが奇数
    cout << s.size()*(k/2)+(s.size()/2)*(k%2) << endl;
    return 0;
  }
  if(s[s.size()-1] == s[0] && (l+r)%2 == 0 && g) ans += k-1;
  cout << ans << endl;

  return 0;
}
