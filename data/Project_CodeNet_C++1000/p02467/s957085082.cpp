#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
using namespace std;
int n;

int main(){
  cin >> n;
  int def_half_n = n/2+2;
  int def_n = n;
  cout << n << ":";
  while(n%2==0){
    cout << " " << 2;
    n /= 2;
  }
  if(n==1){cout << endl; return 0;}
  for(int i = 3;i<def_half_n;i+=2){
    while(n%i==0){
      cout << " " << i;
      n /= i;
    }
    if(n==1)break;
  }
  if(n == def_n)cout << " " << n;
  cout << endl;
  return 0;
}