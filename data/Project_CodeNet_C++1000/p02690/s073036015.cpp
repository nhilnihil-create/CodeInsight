#include <bits/stdc++.h>
using namespace std;

int X;
bool a=false;
void func(){
  for(int i=-200;i<201;i++){
    for(int j=-200;j<201;j++){
      if(pow(i,5)-pow(j,5)==X){
        cout << i << " " << j << endl;
        a=true;
        return ;
      }
    }
  }
}
int main(){
  cin >> X;
  func();
}