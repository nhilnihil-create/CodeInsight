#include <math.h>

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    string k, l;
    string alp[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                      "j", "k", "l", "m", "n", "o", "p", "q", "r",
                      "s", "t", "u", "v", "w", "x", "y", "z"};
    cin >> k >> l;
    for (int i = 0; i < 26;i++){
        if(k+alp[i]==l){
            cout << "Yes" << endl;
            break;
        }else if(i==25){
            cout << "No" << endl;
        }
    } return 0;
}