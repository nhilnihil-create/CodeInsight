#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int     N;
    cin >> N;
    
    while ( 1 ) {
        N = N - 1000;
        if ( N <= 0 ) {
            N = -N;
            break;
        }
    }
    
    cout << N << endl;
    
    return 0;
}