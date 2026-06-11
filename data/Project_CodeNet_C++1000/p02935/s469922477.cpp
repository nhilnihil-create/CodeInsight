#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mod 1000000007
#define ar array
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

void init() {
  int n;
  cin >> n;
  cout << fixed << setprecision(10);
  priority_queue<double, vector<double>, greater<double>> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    q.push(a * 1.0);
  }
  while (q.size() > 1) {
    double tp1 = q.top();
    q.pop();
    double tp2 = q.top();
    q.pop();
    double ans = tp1 + tp2;
    q.push(ans/2);
  }
  cout << q.top() << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
