#include <bits/stdc++.h>
using namespace std;

int gcd(int A,int B){
  if(B==0){
    return A;
  }
  return gcd(B,A%B);
}
int main(){
  long long A,B;
  cin >> A >> B;
  long long C=A/gcd(A,B)*B;
  cout << C << endl;
}