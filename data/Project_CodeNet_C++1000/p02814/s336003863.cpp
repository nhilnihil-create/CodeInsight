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
  ll n,m;
  cin >> n >> m;
  vector<ll> num(n);
  for(int i = 0;i < n;i++)cin >> num[i],num[i] /= 2;
  ll k = -1;
  for(int i = 0;i < n;i++){
    ll nowk = 0;
    while(num[i] % 2 == 0)nowk++,num[i] /= 2;
    if(k == -1)k = nowk;
    else if(k != nowk){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i = 0;i < k;i++)m /= 2;
  //cout << num[0] << " " << num[1] << endl;
  ll lc = 1;
  for(int i = 0;i < n;i++){
    lc = lc * num[i] / __gcd(lc,num[i]);
    if(lc > m){
      cout << 0 << endl;
      return 0;
    }
  }
  //cout << lc << endl;
  if(lc > m)cout << 0 << endl;
  else cout << (m / lc + 1) / 2 << endl;
}