#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;


int main() {
  int a,b,c;
  cin >> a >>b>>c;
  if (a < b && b < c) {
  cout << "Yes" << endl;
  } else {
  cout << "No" << endl;
  }
  return 0;
}

