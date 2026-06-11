#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

const string YES = "Yes";
const string NO = "No";

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;

  if ((A == B && A != C) || (A == C && A != B) || (B == C && B != A))
    cout << YES << endl;
  else
    cout << NO << endl;
}
