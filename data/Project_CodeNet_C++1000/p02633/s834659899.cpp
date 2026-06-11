#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n;
  int result = 0;
  int a=0;
  int b=0;
  cin >> n;
  while(1){
    while(a<360){
      a+=n;
      result++;
    }
    if(a==360){
      break;
    } else {
      a = a % 360;
    }
  }
  cout << result << endl;
  return 0;
}