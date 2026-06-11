#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S >> T;
  int n = S.length();
  int count = 0;
  for(int i = 0; i < n; i++){
    if(S[i] != T[i]){
      count += 1;
    }
  }
  cout << count << endl;
}
