#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    for(int i = 0; i < 3; i++){
        if(S.at(i) == 'R'){
            if(i == 0){
                if(S.at(1) == 'R' && S.at(2) == 'R'){
                    cout << 3 << endl;
                    return 0;
                }
                else if(S.at(1) == 'R'){
                    cout << 2 << endl;
                    return 0;
                }
                else{
                    cout << 1 << endl;
                    return 0;
                }
            }
            else if(i == 1){
                if(S.at(2) == 'R'){
                    cout << 2 << endl;
                    return 0;
                }
                else{
                    cout << 1 << endl;
                    return 0;
                }
            }
            else{
                cout << 1 << endl;
                return 0;
            }
            
        }
        else if(i == 2 && S.at(i) == 'S'){
            cout << 0 << endl;
            return 0;
        }
    } 
}