#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for(int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
  ll x;
  cin >> x;
  for(ll a = -200; a<=200; a++) for(ll b = -200; b<=200; b++) {
    if((a - b) != 0 && x % (a - b) == 0) {
      if(a*a*a*a*a - b*b*b*b*b == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
  return 0;
}