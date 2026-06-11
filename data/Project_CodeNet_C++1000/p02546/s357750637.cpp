#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  string s;
  cin >> s;
  if (s[s.size() - 1] == 's') {
    cout << (s + "es") << endl;
  } else {
    cout << (s + "s") << endl;
  }
}
