#include<iostream>
using namespace std;

int saghf(int a , int b) {
 
  if(a%b == 0){
    return a/b;
  } else {
   	return a/b +1; 
  }
}

int main() {
   
  int l , r , d;
  cin >> l >> r >> d;
  int a = saghf(l,d);
  int b = r/d;
  cout << b-a+1 << "\n";
  
}