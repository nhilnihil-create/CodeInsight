#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

bool g(string s) {
  for(int i = 0; i < sz(s); i++) if(s[i] != s[sz(s)-1-i]) return false;
  return true;
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << (a*(a-1) + b*(b-1)) / 2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
