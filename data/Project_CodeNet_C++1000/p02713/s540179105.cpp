#include <bits/stdc++.h>
using namespace std;

int gc(int x, int y){
  int t;
  while(y > 0){
    t = x;
    x = y;
    y = t % y;
  }
  
  return x;
}
  

int main(){
  int K, g;
  int gcd = 0;
  cin >> K;
  for(int a = 1; a <= K; a++){
    for(int b = 1; b <= a; b++){
      for(int c = 1; c <= b; c++){
        
        if(a == b && b == c){
          gcd += a;
        }
        
        else if(a == b || b == c){
          gcd += 3 * gc(a, c);
        }
        
        else{
          g = gc(b, c);
          gcd += 6 * gc(a, g);
        }
      }
    }
  }
  cout << gcd << endl;
}
    