#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int ans = a + b + c;
  string print = "win";
  if(ans >= 22){
    print = "bust";
  }
  cout << print << endl;
    
}