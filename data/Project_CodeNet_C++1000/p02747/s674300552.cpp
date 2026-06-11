#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int L = S.size();
  string ans="No";
  
  if(L%2==0){
    int cnt=0;
    for(int i=0; i<L; i+=2){
      if(S.at(i)=='h' && S.at(i+1)=='i') cnt++;
    }
    if(cnt==L/2) ans="Yes";
  }
  cout << ans << endl;
}