#include<bits/stdc++.h>
using namespace std; 
int main(){
  int a, b;
  cin >> a >> b;
  int i;
  int ans = 1;
  for(i = 0; ans < b; i++){
    ans += a - 1;
  }
  cout << i << endl;
}