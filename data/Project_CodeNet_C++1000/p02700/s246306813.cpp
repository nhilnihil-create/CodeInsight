#include<bits/stdc++.h>
using namespace std;

const int MAX = 105;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  for(int i = 0; i < MAX; i++){
    c -= b;
    if(c <= 0){
      cout << "Yes" << endl;
      return 0;
    }
    a -= d;
    if(a <= 0){
      cout << "No" << endl;
      return 0;
    }
  }
  
  return 0;
}