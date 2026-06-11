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
  ll mod = pow(10,9) + 7;
  ll res = 1;
  vector<ll> a(3);
  a[0] = 0,a[1] = 0,a[2] = 0;
  for(int i = 0;i < n;i++){
    ll in;
    cin >> in;
    ll k = 0;
    ll same = -1;
    for(int j = 0;j < 3;j++){
      if(in == a[j])k++,same = j;
    }
    if(k == 0){
      cout << 0 << endl;
      return 0;
    }
    res *= k,res %= mod;
    a[same]++;
  }
  cout << res << endl;
}