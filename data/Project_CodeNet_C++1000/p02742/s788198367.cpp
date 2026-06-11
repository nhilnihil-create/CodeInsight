#include<iostream>
using namespace std;

int main(){
  long long H,W,sum;
  cin >> H >> W;
  if(H>1 && W>1){
  	cout << (H/2)*(W/2)+((H+1)/2)*((W+1)/2) << endl;
  }else{
    cout << 1 << endl;
  }
  return 0;
}