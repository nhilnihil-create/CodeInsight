#include<bits/stdc++.h>
using namespace std;

int main(){
  int a; cin >> a;
  
  a %= 10;
  
  if(a==3) cout << "bon" << endl;
  
  else if(a==0 || a==1 || a==6 || a==8) cout << "pon" << endl;
  
  else cout << "hon" << endl;
}