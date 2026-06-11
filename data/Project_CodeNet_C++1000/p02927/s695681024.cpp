#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>
#include <utility>


using namespace std;
typedef long long ll;

//最小公倍数
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//最大公倍数
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

//for(int i = ; i < ; i++){}

ll lmax(ll s,ll t){
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

ll lmin(ll s,ll t){
  if(s<t){
    return s;
  }
  else{
    return t;
  }
}


int main(){
  int m,d;
  cin>>m>>d;
  if(d<20){
    cout<<0<<endl;
    return 0;
  }
  int c = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 20; j <= d; j++){
      if(i==(j/10)*(j%10)&&j%10>=2){
        
        c++;
       
      }
    }
  }
  cout<<c<<endl;
  return 0;
}
