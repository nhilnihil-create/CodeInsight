#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

const string YES = "YES";
const string NO = "NO";

int main() {
  ll A;
  cin >> A;
  ll V;
  cin >> V;
  ll B;
  cin >> B;
  ll W;
  cin >> W;
  ll T;
  cin >> T;

  bool ans = false;
  if (A < B) {
    ans = A + T * V >= B + T * W;
  } else {
    ans = A - T * V <= B - T * W;
  }

  cout << (ans ? YES : NO) << endl;
}
