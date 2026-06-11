#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  long long a,b;
  long long sa;
  long long kekka = 0;
  bool nearL = true;
  
  cin >> num >> a >> b;
  
  sa = (b - a) % 2;
  
  if(a - 1 <= num - b) nearL = true;
  else nearL = false;
  
  if(sa == 0){
    kekka = (b - a) / 2;
  }else if(nearL == true){
    kekka = a - 1 + 1 + (b - a -1) / 2;
  }else{
    kekka = num - b + 1 + (b - a -1) / 2;
  }
  
  cout << kekka;
}
