#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int X;
  cin >> X;
  for(int i=X;i<1e9;i++){
    bool flag=true;
    for(int j=2;j<=sqrt(i);j++){
      if(i%j==0){
        flag=false;
        break;
      }
    }
    if(flag){
      cout << i << endl;
      return 0;
    }
  }
}