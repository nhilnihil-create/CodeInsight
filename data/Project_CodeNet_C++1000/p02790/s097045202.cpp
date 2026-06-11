#include<bits/stdc++.h>
using namespace std;

int f(int x, int c){
  int res = x;
  for(int i=1; i<c; i++){
    x = x + res*10;
    res = res*10;
  }

  return x;
}


int main(){
  int a, b;
  cin >> a >> b;
  int a2 = f(a, b);
  int b2 = f(b, a); 
  
  if(a2>b2){
    cout << a2 << endl;
  }else{
    cout << b2 << endl;
  }
  

  return 0;
}