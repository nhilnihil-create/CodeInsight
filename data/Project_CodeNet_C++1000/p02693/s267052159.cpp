#include <bits/stdc++.h>
using namespace std;
	
int main() {

  int A,B,C;
  int ans = 0;
  cin >> A >> B >> C;
  for(int i = B;i < C+1;i++){
      if(i % A == 0){
             ans = 1;
             break;
      }
  }
  if(ans != 0)  cout << "OK" <<endl;
  else   cout << "NG" <<endl;
  
}