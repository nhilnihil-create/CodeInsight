#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  string s; cin >> s;
  vector<string> t = {"Sunny", "Cloudy", "Rainy"};
  for (int i = 0; i < 3; i++) {
    if (t.at(i) == s)
    {
      cout << t.at((i+1)%3) << endl;
      break;
    }
  }
}