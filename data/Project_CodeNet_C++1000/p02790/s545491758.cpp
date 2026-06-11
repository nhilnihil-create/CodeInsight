#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  if(A<=B){
    for(int i=0;i<B;i++){
      cout << A;
    }
    cout << endl;
  }
  else{
    for(int i=0;i<A;i++){
      cout << B;
    }
    cout << endl;
  }
}
    