#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; bool flag=false;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      if(i*j == n) {cout << "Yes" << endl; flag=true; break;}
    }
    if(flag == true) break;
  }
  if(flag == false) cout << "No" << endl;
  return 0;
}