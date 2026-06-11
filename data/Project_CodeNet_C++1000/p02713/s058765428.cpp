#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int K;cin>>K;
  
  ll sum=0;
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      for(int k=1;k<=K;k++){
		sum+=gcd(gcd(i,j),k);
      }
    }
  }
  
  cout << sum << endl;
}
