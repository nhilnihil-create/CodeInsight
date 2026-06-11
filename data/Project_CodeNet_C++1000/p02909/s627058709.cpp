#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string S;
  cin >> S;

  if(S == "Sunny") {
    cout << "Cloudy" << endl;
  }

  if (S == "Cloudy") {
    cout << "Rainy" << endl;
  }

  if (S == "Rainy") {
    cout << "Sunny" << endl;
  }
  return 0;
}
