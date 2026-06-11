#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,sum=0;
  cin >> K;
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      for(int l=1;l<=K;l++){
        sum+=gcd(gcd(i,j),l);
      }
    }
  }
  cout << sum;
}