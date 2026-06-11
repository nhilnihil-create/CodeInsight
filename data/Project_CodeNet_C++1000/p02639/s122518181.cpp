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
    int     N;
    int     ans;
    
    ans = 0;
    for ( int ii = 0; ii < 5; ii++ ) {
        cin >> N;
        if ( N == 0 ) {
            ans = ii + 1;
        }
    }
    cout << ans << endl;
    return 0;
}