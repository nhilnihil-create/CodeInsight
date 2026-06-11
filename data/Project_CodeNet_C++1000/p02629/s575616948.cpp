#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

#define ALP 26
#define OFFSET 97
char        out[100000];

int main() {
    long long   N;
    long long   q, r;
    int         cnt = 0;
    
    cin >> N;
    while ( 1 ) {
        N--;
        q = N / ALP;
        r = N % ALP;
        out[cnt] = r + OFFSET;
        cnt++;
        if ( q == 0 ) {
            break;
        }
        N = q;
    }
    
    for ( int ii = cnt - 1; ii >= 0; ii-- ) {
        cout << out[ii];
    }
    cout << endl;
    return 0;
}