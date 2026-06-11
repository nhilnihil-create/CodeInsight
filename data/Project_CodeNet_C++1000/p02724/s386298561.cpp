#include <iostream>
using namespace std;
int main(void){
    int X, x;
    cin >> X;
    x = X%500;
    cout << (X/500)*1000+(x/5)*5;
}