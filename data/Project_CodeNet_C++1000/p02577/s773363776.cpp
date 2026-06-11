#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    string S;
    cin >> S;

    int a, i, l, sum;
    l = S.length();
    sum = 0;
    
    for ( i = 0; i < l; i++){
        a = S.at(i) - '0';
        sum += a;
        sum %= 9;
    }
    
    if (sum == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}

