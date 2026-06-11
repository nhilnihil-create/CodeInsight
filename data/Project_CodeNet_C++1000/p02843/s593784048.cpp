#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
int main(){
  ll x;
  cin >> x;
  ll p=x/100,q=x%100;
  if(5*p>=q){
    cout << 1;
  }else{
    cout << 0;
  }
}