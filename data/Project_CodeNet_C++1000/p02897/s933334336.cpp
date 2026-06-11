#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (void){
    int a;
    cin >> a;
    if (a % 2 == 1){
    cout << fixed << setprecision(10) << ((double)a / (double)2 + 0.5 ) / (double)a << endl;
    } else{
    cout << fixed << setprecision(10) << ((double)a / (double)2 ) / (double)a << endl;    
    }
    return 0;
}

