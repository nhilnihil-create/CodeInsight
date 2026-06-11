#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() 
{
  //ll n; cin >> n;
  //vector<int> a(n);
  //rep(i,n) cin >> a[i];
  ll l, r;
  cin >> l >> r;
  int min = 2020;
  bool flg = false;
  for(ll i=l;i<r;i++){
    for (ll j=i+1;j<r+1;j++){
      if ((i * j) % 2019 < min){
        min = (i * j) % 2019;
      }
      if (min == 0){
        flg = true;
        break;
      }
    }
    if(flg)break;
  }
  cout << min << endl;
  return 0;
}
