#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll dp[200005];

int main() {
  string str;
  cin >> str;

  for (ll i = 0; i < str.length(); i++) {
    if (str[i] == '?') {
      str[i] = 'D';
    }
  }

  cout << str << endl;

}
