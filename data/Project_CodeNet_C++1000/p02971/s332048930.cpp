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
  vector<pair<ll,ll>> a(n);
  for(int i = 0;i < n;i++)cin >> a[i].first,a[i].second = i;
  sort(a.rbegin(),a.rend());
  ll ma = a[0].first;
  ll it = a[0].second;
  bool one = true;
  if(a[0].first == a[1].first)one = false;
  if(one){
    for(int i = 0;i < it;i++)cout << ma << endl;
    cout << a[1].first << endl;
    for(int i = it + 1;i < n;i++)cout << ma << endl;
  }
  else{
    for(int i = 0;i < n;i++)cout << ma << endl;
  }
}


