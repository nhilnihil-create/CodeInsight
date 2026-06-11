#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  
  int a, b, c;
  a = n % 10;
  b = (n - a) / 10 % 10;
  c = (n - b * 10 - a) / 100;
  
  if(a == 7 || b == 7 || c == 7){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}