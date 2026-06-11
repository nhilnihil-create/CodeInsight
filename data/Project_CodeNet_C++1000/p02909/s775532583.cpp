#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  if (s == "Sunny") {
    cout << "Cloudy" << endl;
  } else if (s == "Cloudy") {
    cout << "Rainy" << endl;
  } else {
    cout << "Sunny" << endl;
  }
  return 0;
}
