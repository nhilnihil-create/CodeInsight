#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int X =0;
  
  for (int i=1;i<46298;i++){
    long double j=i*1.08;
    int k=j;
    if (k==N){
      X=i;
      break;
    }
  }
  
  if (X==0){
    cout << ":(" << endl;
  }
  else{
    cout << X << endl;
  }
  return 0;
  
}