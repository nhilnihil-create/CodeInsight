#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int digit = n % 10;
    if(digit == 2 || digit == 4 || digit == 5 || digit == 7 || digit == 9){
        cout << "hon" << endl;
    }
    if(digit == 0 || digit == 1 || digit == 6 || digit == 8){
        cout << "pon" << endl;
    }
    if(digit == 3){
        cout << "bon" << endl;
    }
}
