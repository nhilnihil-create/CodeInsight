#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,as=100;
  cin >> n;
  for(int64_t i=1;;i++){
    as+=(int64_t)as*1/100;
    if(as>=n){
      cout << i << endl;
      break;
    }
  }
}
