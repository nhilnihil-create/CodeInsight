#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main (void){  
    char a;
    cin >> a ;
    if (a <= 'Z') {
        cout << "A" << endl;
    } else {
        cout << "a" << endl;
    } 
    return 0;
}