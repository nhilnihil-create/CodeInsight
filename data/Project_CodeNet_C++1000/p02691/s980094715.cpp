#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<int, int> table;
  for (int i = 1; i <= n; i++) {
    int tmp = table[a[i] + i];
    table[a[i] + i] = tmp+1;
  }

  ll result = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = i - a[i];
    result += table[tmp];
  }

  cout << result << endl;
}
