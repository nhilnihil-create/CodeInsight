#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,M;
  cin >> H>>M;
  
  if (H==1||M==1){
    cout << 1 << endl;
  }
  else if (H%2==1 && M%2==1){
    long long seki=1;
    seki *=H;
    seki *=M;
    seki++;
    seki /=2;
    cout << seki <<endl;
  }
  else{
    long long seki=1;
    seki *=H;
    seki *=M;
    seki /=2;
    cout << seki << endl;
  }
   
    
}