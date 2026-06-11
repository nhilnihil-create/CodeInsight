#include <iostream>

using namespace std;

int main (){

    int x;
    cin  >> x;

int unitDigit = x %10;

if(unitDigit == 2 || unitDigit == 4 || unitDigit == 5 || unitDigit == 7 || unitDigit == 9){
    cout << "hon";
} else if (unitDigit == 3){
    cout << "bon";
} else {
    cout << "pon";
}

    return 0;   
}