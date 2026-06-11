#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  if(n<100){
    cout << "0";
    return 0;
  }else{
    int x=n%100;
    int count=0;
    for(int i=5;i>0;i--){
      count+=x/i;
      x-=(x/i)*i;
    }
    if(n/100>=count){
      cout << "1";
    }else{
      cout << "0";
    }
  }
}