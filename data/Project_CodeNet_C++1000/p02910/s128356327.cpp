#include <bits/stdc++.h>
using namespace std;
int main(){
  string tap;
  cin >> tap;
  
  for(int i=0; i<tap.size() ; i +=2){
    if(tap.at(i) == 'L' ){
      cout << "No" << endl;
      break;
    }
    if(tap.size() - i != 1 && tap.at(i+1) == 'R'){
       cout << "No" << endl;
      break;
    }
    if(tap.size() - i <= 2){
      cout << "Yes" << endl;
    }
  }
}
      


