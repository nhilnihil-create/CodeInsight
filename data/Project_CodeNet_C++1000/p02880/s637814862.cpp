#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int ans = 0;
  for (int i=1 ; i<10 ; i++){
    if (n%i == 0){
      if (n/i < 10){
        ans = 1;
        break;
      }
    }
  }
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}