#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string S, T; cin >> S >> T;
  bool Yes=true;
  int Slength=S.size();
  
  for (int i=0; i<Slength; i++){
    if (S.at(i)!=T.at(i)){
      Yes=false;
      cout << "No" << endl;
      break;
      }
    }
  if(Yes){cout << "Yes" << endl;}
}