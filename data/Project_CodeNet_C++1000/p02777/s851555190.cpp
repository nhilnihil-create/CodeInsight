#include <bits/stdc++.h>
using namespace std;
 
int main(void){
 
 string S,T,U;
  int a,b;
  cin >> S >> T >> a >> b >> U;
  if(U==S){
  	cout << a-1 << " " << b << endl;
  }else if(U==T){
  	cout << a << " " << b-1 << endl;
  }
}