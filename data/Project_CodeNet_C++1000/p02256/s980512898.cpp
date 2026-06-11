#include <iostream>
using namespace std;

int main(void){
    int x, y, a;
    cin >> x >> y;
    if(x < y){
        a = y;
        y = x;
        x = a;
    }
    while(y > 0){
        a = x % y;
        x = y;
        y = a;
    }
    cout << x << endl;
    return 0;
}