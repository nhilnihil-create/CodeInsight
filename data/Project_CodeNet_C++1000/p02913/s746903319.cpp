#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef vector<int> vi;
const ll M = 1e9 + 7;

template<typename T>
vi z_algorithm(T& s, ll n){
    vi res(n);
    res[0] = n;
    ll i1 = 1, i2 = 0;

    while(i1 < n){
        while (i1 + i2 < n && s[i2] == s[i1 + i2]) ++i2;
        res[i1] = i2; if (i2 == 0){++i1; continue;}
        ll i3 = 1;
        while (i1 + i3 < n && i3 + res[i3] < i2){res[i1 + i3] = res[i3]; ++i3;}
        i1 += i3, i2 -= i3;
    }
    return res;
}

int main(void){
  int n, ans = 0; string s;
  cin >> n >> s;
  rep(i, n){
    string ss = s.substr(i, n - i);
    vi res = z_algorithm(ss, n - i);
    rep(j, n - i) ans = max(ans, min(j, res[j]));
  }

  cout << ans << endl;

  return 0;
}
