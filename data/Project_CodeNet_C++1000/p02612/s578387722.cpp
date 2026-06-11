#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
  cin >> n;
 int ans; 
  ans =1000 - (n%1000);
  
  if (n%1000 == 0) {
    cout << 0 <<endl;
  }
 else {
 cout << ans << endl;
 }
  return 0;
}