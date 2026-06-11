#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,i;
  cin >> n;
  while(n){
    i = n%10;
    n/=10;
    if (i==7){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}