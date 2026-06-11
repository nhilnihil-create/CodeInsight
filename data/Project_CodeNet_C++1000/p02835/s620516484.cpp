#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;
  
  if(A1+A2+A3>21){
    cout << "bust" << endl;
  }else{
    cout << "win" << endl;
  }
  
  return 0;
}