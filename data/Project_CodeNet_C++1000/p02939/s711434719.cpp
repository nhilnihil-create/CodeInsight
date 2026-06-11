#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  const int Nlen= S.size();

  int ans= 0;
  int offset= 0;
  string prev= "";
  while(offset < Nlen-2){
    string cand1= S.substr(offset, 1);
    string cand2= S.substr(offset, 2);
    if(cand1 != prev){
      ans++;
      offset+= 1;
      prev= cand1;
    }
    else{
      ans++;
      offset+= 2;
      prev= cand2;
    }
  }
  if(offset==Nlen-2 && prev != S.substr(offset, 1) && S.substr(offset, 1) != S.substr(offset+1, 1)){
    ans+= 2;
  }
  else{
    ans+= 1;
  }

  cout << ans << endl;
}