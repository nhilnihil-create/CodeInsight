#include <bits/stdc++.h>
using namespace std;

int main(){
  string a = "abcdefghijklmnopqrstuvwxyz";
  char C;
  cin >> C;
  for(int i = 0; i < 25; i++){
    if(C == a[i]){
      cout << a[i+1] << endl;
      break;
    }
  }
}

