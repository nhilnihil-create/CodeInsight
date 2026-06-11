#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,sum=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        sum+=gcd(k,gcd(i,j));
      }
    }
  }
  cout << sum << endl;
}
