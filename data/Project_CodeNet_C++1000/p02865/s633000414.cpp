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
set<pair<int, int>> x;
int main() {
  int n;
  cin >> n;
  if (n & 1)
    cout << n / 2 << endl;
  else
    cout << n / 2 - 1 << endl;
}