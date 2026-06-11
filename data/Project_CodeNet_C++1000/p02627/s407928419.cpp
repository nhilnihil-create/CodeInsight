#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

int main() {
    char  s[10];
    
    cin >> s;
    
    if ( s[0] >= 'A' && s[0] <= 'Z' ) {
        cout << "A" << endl;
    } else {
        cout << "a" << endl;
    }
    
    return 0;
    
}