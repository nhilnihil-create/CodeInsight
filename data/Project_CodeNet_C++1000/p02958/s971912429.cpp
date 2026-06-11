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
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i = 0;i < n;i++)cin >> a[i],b[i] = a[i];
  sort(a.begin(),a.end());
  ll k = 0;
  for(int i = 0;i < n;i++){
    if(a[i] != b[i])k++;
  }
  if(k <= 2)cout << "YES" << endl;
  else cout << "NO" << endl;
}