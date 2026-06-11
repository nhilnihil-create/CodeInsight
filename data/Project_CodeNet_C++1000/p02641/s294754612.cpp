#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//------------------------------------------------------//


int main() {
  int x, n;
  cin >> x >> n;
  vec<bool> p(101, false);
  rep(i, n){
    int y;
    cin >> y;
    p[y] = true;
  }
  int l = x, r = x;
  int ans = 0;
  while(ans == 0){
    if(l == 0){
      ans = 0;
      break;
    }
    if(p[l] == false && p[r] == false) ans = l;
    else if(p[l] == false && p[r] == true) ans = l;
    else if(p[l] == true && p[r] == false) ans = r;
    l--;
    r++;
  }
  cout << ans << endl;
  return 0;
}