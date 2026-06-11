#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;


int main(){
  ll x;
  cin >> x;
  ll money = 100;
  ll cnt = 0;
  while(money<x){
    money += money/100;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
