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
  int h, w, n;
  cin >> h >> w >> n;
  cout << int(ceil(1.0 * n / max(h, w))) << endl;
}