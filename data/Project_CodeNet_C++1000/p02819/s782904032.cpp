#include <bits/stdc++.h>
using namespace std;
bool prime(long x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) return false;
  }
  return true;
}
int main(){
  long  x; cin >> x;
  for(long i = x; ; i++){
    if(prime(i)){
      cout << i;
      return 0;
    }
  } 
}