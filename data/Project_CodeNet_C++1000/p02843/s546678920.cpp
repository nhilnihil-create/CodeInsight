#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll X;
  cin >> X;
  if(X % 100 > X / 100 * 5) cout << 0 << endl;
  else cout << 1 << endl;
}