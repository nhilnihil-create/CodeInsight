#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;
  while(!S.empty()){
    if(S.substr(0,2)=="hi"){
      S.erase(0,2);
    }else{
      break;
    }
  }
  if(S.empty()){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}