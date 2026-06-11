#include <bits/stdc++.h>
using namespace std;

int main(){
  int num;
  for(int i=0;i<5;i++){
    cin >> num;
    if(num != i+1){
      cout << i+1;
    }
  }
}