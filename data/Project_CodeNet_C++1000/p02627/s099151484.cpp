#include <bits/stdc++.h>
using namespace std;

int main(){
  char a;
  cin >> a;
  string big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string sml = "abcdefghijklmnopqrstuvwxyz";
  for(int i = 0; i < 26; i++){
    if(big[i] == a){
      cout << "A" << endl;
      break;
    }else if(sml[i] == a){
      cout << "a" << endl;
      break;
    }
  }
}