#include <bits/stdc++.h>
using namespace std;
int main() {
  string S; cin >> S;
  bool ans = true;
  if(S[0]==S[1]) ans= false;
  if(S[1]==S[2]) ans= false; 
  if(S[2]==S[3]) ans = false;
       
  if(ans==false) cout << "Bad" << endl;
  else cout << "Good" << endl;   
}