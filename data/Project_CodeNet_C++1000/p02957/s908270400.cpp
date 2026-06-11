#include<bits/stdc++.h>
using namespace std;

int main(){
 
  long long A, B;
  cin >> A >> B;

  if((A + B) % 2 != 0 || (B + A) % 2 != 0){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  
  if(A > B){
    cout << (A + B) / 2 << endl;
  }else{
    cout << (B + A) / 2 << endl;
  }
  return 0;
}
