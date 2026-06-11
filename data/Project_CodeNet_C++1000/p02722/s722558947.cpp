#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

vector<ll> div(ll n){
  vector<ll> ret;
  ret.clear();
  ll i;
  for(i=2;i*i<n;i++){
    if(n%i==0){
      ret.push_back(i);
      ret.push_back(n/i);
    }
  }
  if(i*i==n){
    ret.push_back(i);
  }

  return ret;
}

int main(void){
  ll n;
  cin >> n;

  if(n==2LL){
    cout << 1 << endl;
    return 0;
  }

  ll cnt = 0;
  auto d = div(n);
  
  ll tmp;
  for(int i=0;i<d.size();i++){
    tmp = n;
    while(tmp%d[i]==0){
      tmp /= d[i];
    }
    if((tmp-1)%d[i]==0){
      ++cnt;
    }
  }

  auto p = div(n-1);

  cnt += p.size();

  cnt += 2;

  cout << cnt << endl;

  return 0;
}
