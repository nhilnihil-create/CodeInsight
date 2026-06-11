#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int h, w, n;
  cin >> h >> w >> n;
  
  int result;
  
  if (h > w){
    result = n / h;
    if (n % h){
      result += 1;
    }
  }
  else{
    result = n / w;
    if (n % w){
      result += 1;
    }
  }
  
  cout << result;
  return 0;
}