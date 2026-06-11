#include<bits/stdc++.h>
using namespace std;

bool is_prime(int a){
  if(a == 1) return false;
  if(a == 2) return true;
  for(int i = 2; i < a; i++){
    if(a % i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int a;
  cin >> a;
  while(true){
    if(is_prime(a)){
      cout << a << endl;
      return 0;
    }
    a++;
  }
}