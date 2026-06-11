#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x,y,count=0,check=0;
  string ans;
  cin >> x >> y;
  int cr,tu;
  for(int i=0; i<=x; i++){
    cr = i; //i = cr
    tu = x-i; 
    if(2 * cr + 4 * tu == y) check = 1;
  }
  if(check !=0){
    ans = "Yes";
  }else{
    ans = "No";
  }
  cout << ans << endl;
}