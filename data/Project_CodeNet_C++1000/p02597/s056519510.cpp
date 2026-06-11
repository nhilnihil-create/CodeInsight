#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    int i, j, N, flag_r, flag_w, count;
    cin >> N;
    flag_r = 0;
    flag_w = 0;
    count = 0;
    
    int L[N];

    string S;
    cin >> S;
    
    for (i = 0; i < N; i++){
        if (S.at(i) == 'R'){
            L[i] = 1;
            flag_r = 1;
            
        } else {
            L[i] = 0;
            flag_w = 1;
        }
    }
        
    if (flag_r == 0 || flag_w == 0){
        cout << "0" << "\n";
        return 0;
    }
    
    i = 0;
    j = N - 1;
    
    while(1){
        
        while(L[i] == 1){
            i++;
        }

        while(L[j] == 0){
            j--;
        }
        
        if (i > j) break;
        
        L[i] = 1;
        L[j] = 0;
        count++;
    }
    
    cout << count << "\n";

    return 0;
}

