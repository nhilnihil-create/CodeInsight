#include <iostream>
using namespace std;
int main(void){
    
    string S, T;
    cin >> S >> T;
    
    int cnt = 0;
    
    for(int i = 0; i < S.size(); i++){
        if(S[i] != T[i]) cnt++;
    }
    
    if(cnt > 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}
