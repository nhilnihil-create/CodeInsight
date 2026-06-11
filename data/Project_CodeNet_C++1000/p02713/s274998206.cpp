#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K;
  int S=0;
  cin>>K;
  for(int A=1;A<=K;A++){
    for(int B=1;B<=K;B++){
      for(int C=1;C<=K;C++){
        S+=__gcd(A,__gcd(B,C));
      }
    }
  }
  cout<<S<<endl;
}