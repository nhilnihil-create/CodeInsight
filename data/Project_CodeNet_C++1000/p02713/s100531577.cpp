#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int p, int q){
  if(p%q==0)return q;
  return gcd(q, p%q);
}

int main(){
  int k, sum=0;
  cin >> k;
  rep(i, k){
    rep(j, k){
      rep(l, k){
        sum+=gcd(gcd(i+1, j+1), l+1);
      }
    }
  }

  cout << sum << endl;

  return 0;
}