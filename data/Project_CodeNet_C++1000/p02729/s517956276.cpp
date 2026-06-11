#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
int main() {
  int n, m;
  cin >> n >> m;
  cout << m * (m - 1) / 2 + n * (n - 1) / 2 << endl;
}