#include <iostream>
using namespace std;

int X;

int main(){
    cin >> X;
    int able = X / 100;
    
    if(5 * able >= X - (able * 100)){
        cout << 1 << endl;
        exit(0);
    }
    cout << 0 << endl;
}