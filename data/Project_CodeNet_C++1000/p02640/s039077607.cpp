#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

#define KAME 4
#define TSURU 2

int main() {
    int     X, Y;
    
    cin >> X >> Y;
    
    for ( int ii = 0; ii <= X; ii++ ) {
        if ( ii * KAME + (X - ii) * TSURU == Y ) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}