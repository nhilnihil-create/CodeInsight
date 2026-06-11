#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  unsigned int k;
  cin >> k;
  vector<ll> a;
  for(int i=1;i<=9;++i) a.push_back(i);
  while(1){
    vector<ll> pre_a;
    if(k<=a.size())break;
    k-=a.size();
    swap(pre_a,a);
    for(ll j:pre_a){
      for(ll i=-1;i<=1;++i){
        ll m=j%10+i;
        if(m<0||9<m) continue;
        ll n=j*10+m;
        a.push_back(n);
      }
    }
  }
  cout << a[k-1] << endl;
  return 0;
}