#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
  int k,mini,maxi;
  cin >> k >> mini >> maxi;
  int l = (maxi/k)*k;
  if( l >= mini){
    cout << "OK" << endl;
  }
  else{
    cout << "NG" << endl;
  }
  
}