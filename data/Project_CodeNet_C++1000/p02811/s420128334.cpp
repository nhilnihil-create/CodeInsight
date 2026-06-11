#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (void){
    int k, x;
    cin >> k >> x;
    if (x <= 500 * k){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}