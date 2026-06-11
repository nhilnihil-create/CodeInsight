#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool a=false;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if((i+1)*(j+1)==N){
        a=true;
      }
    }
  }
  if(a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}