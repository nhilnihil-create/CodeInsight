#include<bits/stdc++.h>
using namespace std;
int main(){
  double A,B;
  cin >> A >> B;
  for(int i = 0; i < 2000; i++){
    double tax_8 = i*0.08;
    if(floor(tax_8) == A){
      double tax_10 = i*0.1;
      if(floor(tax_10) == B){
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}