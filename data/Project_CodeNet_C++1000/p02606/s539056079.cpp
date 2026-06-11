#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C;
  D=0;
  
  for (int i=A;i<=B;i++){
    if(i%C==0){D++;}
  } 
  cout << D << endl;
}