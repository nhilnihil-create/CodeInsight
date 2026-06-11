#include <bits/stdc++.h>
using namespace std;

int main() {
  string hitachi;
  cin >> hitachi;
  int count = 0;
  for(int i = 0; i < hitachi.size()-1; i++){
    if(hitachi.at(i) == 'h' && hitachi.at(i+1) == 'i'){
      count++;
    }
  }
  
  if(hitachi.size() % 2 == 0 && count == hitachi.size()/2){
  cout << "Yes" << endl;
  }
  
  else{
    cout << "No" << endl;
  }
}
