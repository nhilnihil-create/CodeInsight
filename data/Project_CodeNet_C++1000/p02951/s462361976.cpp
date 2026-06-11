#include<bits/stdc++.h>

using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  
  int rest = A-B;
  
  if(rest>C){
    cout << 0 << endl;
  }else{
    cout << C-rest << endl;
  }

  return 0;
}