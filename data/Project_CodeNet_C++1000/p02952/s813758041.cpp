#include<bits/stdc++.h>
using namespace std;

int main(){
  int a;
  cin >> a;
  if(a < 10){
    cout << a << endl;
  }else if(10 <= a && a < 100){
    cout << 9 << endl;
  }else if(100 <= a && 999 >= a){
    cout << 9 + (a - 100 + 1) << endl;
  }else if(1000 <= a && a <= 9999){
    cout << 909 << endl;
  }else if(10000 <= a && a <= 99999){
    cout << 909 + (a - 10000 + 1) << endl;
  }else{
    cout << 90909 << endl;
  }
}