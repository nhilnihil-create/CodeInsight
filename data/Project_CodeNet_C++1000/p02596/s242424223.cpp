#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    int i, K, rem;
    cin >> K;
    rem = 0;
    
    for (i = 1; i <= K; i++){

        rem = rem * 10 + 7;
        rem = rem % K;
        if (rem == 0) break;
    }
    
    if (rem == 0){
        cout << i << "\n";
    } else {
        cout << "-1" << "\n";
    }

    return 0;
}

