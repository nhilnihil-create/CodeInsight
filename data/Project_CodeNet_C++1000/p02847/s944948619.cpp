#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unordered_map<string, int> ma;
  ma["SUN"] = 7;
  ma["MON"] = 6;
  ma["TUE"] = 5;
  ma["WED"] = 4;
  ma["THU"] = 3;
  ma["FRI"] = 2;
  ma["SAT"] = 1;
  cin >> s;
  cout << ma[s] << endl;
  
  return 0;
}
