#include <iostream>
using namespace std;
//Ninda Irvany

int main() {
    int x, y, z;
    cin >> x >> y;
    z = x*y;
    if(z>5) {
        cout << 1 << endl;
    }else if(z>2) {
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
    }
    return 0;
}
