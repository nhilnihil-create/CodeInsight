#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  if(2 * x >= a * a * b) cout << fixed << setprecision(15) << atan(double(2 * (b - double(x) / double(a * a))) / double(a)) / 3.1415926535897932384626433832795028841971 * 180 << endl;
  else cout << fixed << setprecision(15) << atan(double(a * b * b) / double(2 * x)) / 3.1415926535897932384626433832795028841971 * 180 << endl;
}