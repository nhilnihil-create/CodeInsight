#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a,int64_t b){
  while(b!=0){
    int64_t temp=a%b;
    a=b;
    b=temp;
  }
  return a;
}

int main(){
  int X;
  cin >> X;
  cout << 360/gcd(X,360) << endl;
  return 0;
}
