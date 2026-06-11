#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,K;
  cin >> A >> B >> C>> K;
  
  int counter=0;
  while(B<=A){
    counter++;
    B*=2;
  }
  while(C<=B){
    counter++;
    C*=2;
  }
  if(counter<=K){
    cout << "Yes";
  }else{
    cout << "No";
  }
}