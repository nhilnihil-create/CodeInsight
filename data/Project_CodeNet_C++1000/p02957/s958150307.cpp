#include <iostream>
#include <string>
using namespace std;

int main (void){
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << a << endl;
    }else if((a % 2) == (b % 2)){
        cout << (a + b) / 2 << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

