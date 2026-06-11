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
  int n, r;
  cin >> n >> r;
  if (n >= 10)
    cout << r << endl;
  else {
    cout << r + 100 * (10 - n) << endl;
  }
}