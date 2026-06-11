#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int main(){
  ll x, k, d; cin>>x >>k >>d;
  if(x<0) x *= -1;
  if(x / d >= k) cout<< x - d * k <<endl;
  else{
    ll  a = x / d;
    k -= a;
    x -= a * d;
    if(k % 2 == 0) cout<< x <<endl;
    else cout<< d - x <<endl;
  }
}
