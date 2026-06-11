#include<bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  int ans = 1;
  for(int i = 1; ; i++){
    if(i * 360 % x == 0){
      cout << (i * 360) / x << endl;
      return 0;
    }
  }
}