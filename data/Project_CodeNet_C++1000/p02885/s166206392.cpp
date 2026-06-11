#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (void){
    int a, b;
    cin >> a >> b;
    if(0 < a - (b * 2)){
        cout << a - (b * 2) << endl;
    }else{
        cout << "0" << endl;
    }
    return 0;
}

