#include<iostream>
using namespace std;
int main(){
  int n = 5;
  int a[n], b[n];
  for(int i = 1; i < 6; i++){
    a[i] = i;
    cin >> b[i];
    if(a[i] != b[i]){
      cout << i <<"\n";
      return 0;
  }
  }
}