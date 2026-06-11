#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        int tmp;
        cin >> tmp;
        
        if(tmp % 2 == 0){
            if(tmp % 3 == 0 || tmp % 5 == 0) continue;
            
            cout << "DENIED" << endl;
            return 0;
        }
    }
    
    cout << "APPROVED" << endl;
    return 0;
}