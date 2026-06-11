#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

int ceil(int x, int y) { return (x % y == 0) ? x / y : x / y + 1; }

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;


  int sum[10][10];
  for(int i = 0; i < 10; i++){
    fill(sum[i], sum[i] + 10, 0);
  }

  string s;
  for(int i = 1; i <= n; i++){
    s = to_string(i);
    int j = 0;
    while(j < s.length() && s[j] == '0') ++j;
    int x = s[s.length()- 1] - '0';
    int y = s[j] - '0';
    sum[x][y]++;
  }

  int count = 0;
  for(int i = 1; i <= n; i++){
    s = to_string(i);
    int j = 0;
    while(j < s.length() && s[j] == '0') ++j;
    int x = s[s.length()- 1] - '0';
    int y = s[j] - '0';
    count += sum[y][x];
  }

  cout << count << endl;

  return 0;
}
