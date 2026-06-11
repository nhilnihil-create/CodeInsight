#include <iostream>
#include <string>
using namespace std;

int main (void){
    int a, b, c, x;
    cin >> a >> b >> c;
    x = c - (a - b);
    if(0 < x){
        cout << x << endl;
    }else{
        cout << "0" << endl;
    }
    return 0;
}

