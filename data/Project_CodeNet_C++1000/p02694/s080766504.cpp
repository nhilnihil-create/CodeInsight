#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  ll x;
  cin >> x ;
  ll ans = 0, money = 100;
  while(money < x){
    money += money/100;
    ++ans;
  }
  cout << ans << "\n";
}