#include <bits/stdc++.h>
using namespace std;
int main(void){
    int K;
    string S;
    cin >> K >> S;
  
    if(K >= S.size()) {
        cout << S << endl;
    } 
    else {
        for (int i=0;i<K;i++) {
            cout << S[i];
        }
        cout << "..." << endl;
    }
   
 
    
}
