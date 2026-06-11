#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int X=0;
  cin >> S;
  int Y=S.size();
  
  for(int i=0; i < Y/2; i++){
   if(S[i] != S[Y-i-1]){
     X++;
   }
  }
  cout << X << endl;
}
