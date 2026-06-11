#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
  int x,y,sum;
  bool flag=false;
  cin >> x >> y;
  for(int i=0;i<=x;i++){
    sum = 2*i + 4*(x-i);
    if(sum == y){
      flag = true;
      break;
    }
  }
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}