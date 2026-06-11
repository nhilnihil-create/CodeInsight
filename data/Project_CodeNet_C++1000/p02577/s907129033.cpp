#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  
  int s = N.size();
  int x;
  int ans = 0;
  
  for(int i=0;i<s;i++){
    x = N[i] - 48;
    ans += x;
  } 
  
  if(ans % 9 == 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
