#include <bits/stdc++.h>
using namespace std;
int main(void){
    string S,T;
    cin >> S >> T;
    
    bool match=true;
    
    if(S.size()+1!=T.size()) {
        cout << "No" << endl;
        match=false;
    }
     else { 
         for (int i=0;i<S.size();i++) 
          if(S[i]!=T[i]) {
              cout << "No" << endl;
              match=false;
              break;
          }
     
    }
    
    if(match==true) {
        cout << "Yes" << endl;
    }
    
    
}
