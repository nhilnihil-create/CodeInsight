#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  int sum=X;
  for(int i=1;;i++){
    if(sum%360==0){
      cout << i << endl;
      break;
    }
    sum+=X;
  }
  return 0;
}
