#include <atcoder/all>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll digitcal(ll x){
  ll n=0;
  while(x>0){
    x/=10;
    n++;
  }
  return n;
}

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main() {
  string s;
  s="ACL";
  int k;
  cin>>k;
  for(int i=0;i<k;i++){
    cout<<s;
  }
  cout<<endl;
  return 0;
}