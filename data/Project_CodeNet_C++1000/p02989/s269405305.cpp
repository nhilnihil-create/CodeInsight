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
  ll n; cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];
  //ソートして真ん中のindexを調べて、その間のかずじゃん
  //真ん中2つが同じだったらぜろジャン
  sort(d.begin(), d.end());
  int middle1 = n / 2 - 1;
  int middle2 = n / 2;
  int ans;

  if (d[middle1] == d[middle2]){
    ans = 0;
  }else{
    ans = d[middle2] - d[middle1];
  }

  cout << ans << endl;
  return 0;
}