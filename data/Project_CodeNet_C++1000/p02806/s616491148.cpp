#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
  ll n;
  cin >> n;
  VS s(n);
  VL t(n);
  rep(i, 0, n) cin >> s[i] >> t[i];
  string x;
  cin >> x;
  ll ans = 0;
  rep(i, 0, n){
    ans += t[i];
    if(s[i] == x) break;
  }
  cout << accumulate(ALL(t),0LL) - ans << endl;
    return 0;
}
