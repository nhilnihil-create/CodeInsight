#include <bits/stdc++.h>
using namespace std;

int main(){
 
  int K,A,B,n;
  cin >> K >> A >> B;
  
  n = (A/K+1)*K;
  
  if ((A % K == 0) || (n <= B))
    cout << "OK\n";
  else
    cout << "NG\n";

  return 0;
}