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
  ll wa = 0;
  vector<ll> a(n);
  ll res = 1000000000000000;
  for(int i = 0;i < n;i++)cin >> a[i],wa += a[i];
  ll now = 0;
  for(int i = 0;i < n;i++){
    now += a[i];
    res = min(res,abs(wa - now - now));
  }
  cout << res << endl;
}