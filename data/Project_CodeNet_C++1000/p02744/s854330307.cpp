#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n = 0;
void dfs(string cur, char mx) {
  if(cur.size() == n) {
    cout << cur << endl;
    return;
  }
  for(char c = 'a'; c <= mx + 1; c++) {
    string t = string(cur + c);
    dfs(t, max(c, mx));
  }
}
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  //everytime when i do virtual contest someone disturbs, wtf

  cin >> n;

  dfs("a", 'a');

  return 0;
}
/*

*/
