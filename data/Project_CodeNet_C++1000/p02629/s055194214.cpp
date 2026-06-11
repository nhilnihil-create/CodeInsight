#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int mod = 26;

char fun(int x){
    
    if (x == 1) return 'a';
    if (x == 2) return 'b';
    if (x == 3) return 'c';
    if (x == 4) return 'd';
    if (x == 5) return 'e';
    if (x == 6) return 'f';
    if (x == 7) return 'g';
    if (x == 8) return 'h';
    if (x == 9) return 'i';
    if (x == 10) return 'j';
    if (x == 11) return 'k';
    if (x == 12) return 'l';
    if (x == 13) return 'm';
    if (x == 14) return 'n';
    if (x == 15) return 'o';
    if (x == 16) return 'p';
    if (x == 17) return 'q';
    if (x == 18) return 'r';
    if (x == 19) return 's';
    if (x == 20) return 't';
    if (x == 21) return 'u';
    if (x == 22) return 'v';
    if (x == 23) return 'w';
    if (x == 24) return 'x';
    if (x == 25) return 'y';
    if (x == 26) return 'z';

    return 'E';
}

int main(){
    
    long i, N;
    cin >> N;

    int X[20] = {};
    int count = 0;
    
    while(N > 0){
        
        if (N % mod == 0){
            
            X[count] = mod;
            N = N / mod - 1;
            count++;

        } else {
            X[count] = N % mod;
            N /= mod;
            count++;
        }
    }
    
    for (i = 0; i < count; i++){
        
        cout << fun(X[count - 1 - i]);
    }
    
    cout << "\n";

    return 0;
}

