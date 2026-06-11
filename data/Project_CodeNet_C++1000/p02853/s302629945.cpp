#include <bits/stdc++.h>
using namespace std;

int main(){
  int imp;
  int cord;
  int sum;
  
  cin >> imp >> cord;
  if(imp == 1){
    sum = sum + 300000;
  }
  else if(imp == 2){
    sum = sum + 200000;
  }
  else if(imp == 3){
    sum = sum + 100000;
  }
    if(cord == 1){
    sum = sum + 300000;
  }
  else if(cord == 2){
    sum = sum + 200000;
  }
  else if(cord == 3){
    sum = sum + 100000;
  }
  
  if(imp + cord == 2){
    sum = sum + 400000;
    }
  cout << sum << endl;
}