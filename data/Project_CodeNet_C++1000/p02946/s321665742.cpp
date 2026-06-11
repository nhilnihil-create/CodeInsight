#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int K,X;
   cin >> K >> X;
   int l = X - K + 1;
   int r = X + K - 1;
  for(int i=l;i<=r;i++){
      if(i != r) cout << i << " ";
      if(i == r) cout << i << endl;
  } 
}