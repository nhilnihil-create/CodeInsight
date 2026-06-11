#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
 
  int n =0;
  for(int i=0;i<3;i++){
    if(S.at(i)=='R'){
      n++;
    }
  }
  
  if(n==2 && S.at(1)=='S'){
    n --;
  }
  
  cout << n << endl;
}
