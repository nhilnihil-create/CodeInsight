// Copyright 2015 KanatoNagayama
#include <iostream>
#include <vector>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: vector;
int main() {
  vector<int> v(10000);
  int i = 0;
  while(true) {
    cin >> v[i];
    if(v[i] == 0)
      break;
    i++;  
  }
  for (int k = 0; k < i; k++) {
  cout << "Case " << k + 1 << ": " <<  v[k] << endl;
  }
  return 0;
}