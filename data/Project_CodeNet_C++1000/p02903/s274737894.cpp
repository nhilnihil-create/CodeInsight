#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  rep(i,b){
    rep(j,a) cout << 0;
    rep(j,w-a) cout << 1;
    cout << endl;
  }
  rep(i,h-b) {
    rep(j,a) cout << 1;
    rep(j,w-a) cout << 0;
    cout << endl;
  }
  return 0;
}