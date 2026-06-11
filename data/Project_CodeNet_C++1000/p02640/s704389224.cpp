#include <iostream>
using namespace std;
int main() {
    int X,Y;
    cin >> X >> Y;
    if (Y%2==1) {
        cout << "No" << endl;
    }
    else {
        if (X*4<Y||X*2>Y) 
           cout << "No" << endl;
        else {
            cout << "Yes" << endl;
        }
    }
}
