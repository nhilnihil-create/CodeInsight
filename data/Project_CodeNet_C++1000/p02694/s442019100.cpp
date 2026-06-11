#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a=100, x,i=0;
  cin >> x;
  while(true){
    i++;
    a+=a/100;
    if(a>=x){
      break;
    }
  }
  cout << i <<endl;
  
  return 0;
}
