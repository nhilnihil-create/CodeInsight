#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
const ll mod=1000000007;

main(){
  ll x,k,d;cin >> x >> k >> d;
  x=abs(x);
  ll straight = min(k,x/d);
  k-=straight;
  x-=straight*d;
  if(k%2 == 0){
    cout << x << endl;
  } else {
    cout << d-x << endl;
  }
}


