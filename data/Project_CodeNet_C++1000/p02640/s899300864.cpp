#include <bits/stdc++.h>
using namespace std; 

int main(){
  int X,Y;
  cin >> X >> Y;
  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
      int A=i,B=j;
      if(A+B==X && A*2+B*4==Y){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}