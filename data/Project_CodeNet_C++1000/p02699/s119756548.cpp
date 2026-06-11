#include <bits/stdc++.h>
using namespace std;

int main(){
  int Sheep,Wolf;
  cin >> Sheep >> Wolf ;
  
  if(Sheep > Wolf){
    cout << "safe" << endl;
  }else{
    cout << "unsafe" << endl;
  }
}