#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  bool t=true;
  int count=0;
  for(int i=1;i<10;i++){
    count++;
    if(i==n){
      t=false;
      cout << count << endl;
      break;
    }
  }
  if(t){
    if(n<100){
      t=false;
      cout << count << endl;
    }else{
      for(int i=100;i<1000;i++){
        count++;
        if(i==n){
          t=false;
          cout << count << endl;
          break;
        }
      }
    }
  }
    if(t){
      if(n<10000){
        t=false;
        cout << count << endl;
      }else{
      for(int i=10000;i<100000;i++){
        count++;
        if(i==n){
          t=false;
          cout << count << endl;
          break;
        }
      }
      }
    }
  if(t)cout << count << endl;
}