#include <bits/stdc++.h>
using namespace std;

long long  pow5(long long a){
  return a*a*a*a*a;
}

int main(){
  long long X,Am,a,b,i,j;
  cin >> X;
  Am=1;
  while(pow5(Am)-pow5(Am-1) < X) Am++;
  for(i=0;i<=Am;i++){
    a = pow5(i);
    for(j=-Am;j<=Am;j++){
      b = pow5(j);
      if (a-b == X){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
      
  
  return 0;
}