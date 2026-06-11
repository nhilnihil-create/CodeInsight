#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define deb(x) cout << #x << " " << x << endl;
#define debarr(x) for (auto i : x) cout << i << " "; cout << endl;
#define debtwo(x,y) cout << #x << " " << x << ", " << #y << " " << y << endl;
#define mod 1000000007

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b;
  cin >> n;

  bool f = 0;
  int c = 0;
  while (n--) {
    cin >> a >> b;
    if (a == b) c++;
    else c = 0;
    if (c == 3) f = 1;
  }
  if (f) cout << "Yes";
  else cout << "No";
}