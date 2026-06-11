#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  int ans = 1;
  if (n%2 == 0){
    for (int i=0 ; i<n/2 ; i++){
      if (s.at(i) != s.at(n/2+i)){
        ans = 0;
        break;
      }
    }
  }
  else
    ans = 0;
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}