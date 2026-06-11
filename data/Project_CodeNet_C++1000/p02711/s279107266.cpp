#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool a=false;
  while(N){
    if(N%10==7){
      a=true;
    }
    N/=10;
  }
  if(a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
    