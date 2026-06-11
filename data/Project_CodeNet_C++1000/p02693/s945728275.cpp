#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a,b,counts =0;
  cin >> k >> a >> b;
  for(int i = 0; i < 142; i++){
    if( k*i >= a && k*i <= b){
      counts++;
    }
  }
  if(counts == 0){
    cout << "NG" << endl;
  }
  else{
    cout << "OK" <<endl;
  }
}