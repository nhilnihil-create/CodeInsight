#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  double res = 0;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  sort(a.begin(),a.end());
  res += a[0];
  for(int i = 1;i < n;i++)res += a[i],res /= 2;
  cout << fixed << setprecision(10) << res << endl;
}
