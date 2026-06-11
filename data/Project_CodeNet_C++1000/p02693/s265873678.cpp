#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main (void){
    int a, b, k;
    int cnt = 0;
    cin >> k >> a >> b;
    
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            cnt++;
            break;
        } 
    }

    if (0 < cnt) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }

    return 0;
}