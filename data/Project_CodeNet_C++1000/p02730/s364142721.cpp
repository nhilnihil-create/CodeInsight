#include <bits/stdc++.h>
using namespace std;
bool Check(string S,int l,int r){
    
    l--;
    r--;
    
    while(1){
        
        if(S[l] != S[r]) return false;
        l++;
        r--;
        if(r < l) break;
    }
 
    return true;
}

int main(void){
    
  string S;
  cin >> S;
  int N = S.size();
  
  if(Check(S,1,N) && Check(S,1,(N-1)/2) && Check(S,(N+3)/2,N)) cout << "Yes" << endl;
  else cout << "No" << endl;
}