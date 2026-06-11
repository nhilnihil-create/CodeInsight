#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  ll ans = 1;
  vector<int> num(3, -1);
  cin >> n;
  vector<int> table(n);
  rep(i, 0, n) {
    int check = 0;
    cin >> table[i];
    rep(j,0,3){
      if(num[j]==table[i]-1){
        if (check == 0){
          num[j]++;
        }
        check++;
      }
    }
    ans *= check;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}