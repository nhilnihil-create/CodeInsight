#include <bits/stdc++.h>
#include<fstream>
using namespace std;

int main(){
  int n;
  cin >> n;
  bool ans = false;
  for(int i = 1; i <= 9; ++i ){
    for(int j = 1; j <= 9; ++j ){
      int num = i * j;
      if(n % num == 0 && n/num == 1){
        ans = true;
        break;
      }
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}