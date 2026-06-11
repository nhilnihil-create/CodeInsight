#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int A,B,a,b;
  cin >> A >> B;
  if(A<B){
   a = B;
   b = A;
  }else{
    a = A;
    b = B;
  }
  long long int p = a%b;
  while(p!=0){
    a = b;
    b = p;
    p = a%b;
  }
  long long int ans = A/b*B;
  cout << ans << endl;
}    