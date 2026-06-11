#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    for(int i = 1 ; i <= 9 ; i++){
        for(int j = 1 ; j <= 9 ; j++){
            if(N == i*j){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}