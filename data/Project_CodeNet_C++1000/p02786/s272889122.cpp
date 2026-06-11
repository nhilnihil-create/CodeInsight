#include <bits/stdc++.h>
using namespace std;

int main(){
  long long H;
  cin >> H;
  long long ruijo = 0, result;
  while(true){
    if(pow(2, ruijo) <= H){
      result = ruijo;
      ruijo++;
    }
    else break;
  }
  cout << (long long)pow(2, result + 1) - 1 << endl;
}