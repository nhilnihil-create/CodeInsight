#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    
    int i, N, count = 0;
    
    string S, T;
    cin >> S >> T;
    
    N = S.size();
    
    for (i = 0; i < N; i++){
        
        if (S.at(i) != T.at(i)) count++;
    }
    
    cout << count << "\n";

    return 0;
}

