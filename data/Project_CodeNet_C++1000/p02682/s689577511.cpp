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

 
int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int ans = 0;
  if(a >= k){
    ans = k;
  }
  else if(a + b >= k){
    ans = a;
  }
  else{
    ans = a - (k - (a + b));
  }
  cout << ans << endl;
  return 0;
}