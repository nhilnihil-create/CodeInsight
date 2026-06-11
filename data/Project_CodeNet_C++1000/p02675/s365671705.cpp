#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  n = n % 10;

  switch (n) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      cout << "hon" << endl;
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      cout << "pon" << endl;
      break;
    case 3:
      cout << "bon" << endl;
  }
}