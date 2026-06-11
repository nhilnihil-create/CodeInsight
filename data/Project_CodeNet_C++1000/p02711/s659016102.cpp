#include <bits/stdc++.h>
using namespace std;

int main(void){
    string N;
    cin >> N;
    
    for(int i = 0; i < N.size(); i++){
        if(N[i] == '7'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}