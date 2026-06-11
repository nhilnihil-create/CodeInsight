#include <bits/stdc++.h>
#include <cassert>
#include <numeric>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(a%b,b);
}

int main() {
  ll K,ans=0,temp;
  cin >> K;
 
  for(int a=1;a<K+1;a++){
    for(int b=1;b<K+1;b++){
      for(int c=1;c<K+1;c++){ 
        temp = gcd(gcd(a,b),gcd(b,c));
        ans = ans + temp;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}