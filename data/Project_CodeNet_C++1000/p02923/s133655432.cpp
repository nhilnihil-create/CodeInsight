#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,h;
  cin >> n >> h;
  
  int idou = 0,saidai = 0,next;
  
  for ( int i = 1; i < n; i++){
    cin >> next;
    if ( h >= next ){
      idou++;
      saidai = max(saidai,idou);
    }else{
      idou = 0;
    }
    h = next;
  }
  
  cout << saidai << endl;   
  
}