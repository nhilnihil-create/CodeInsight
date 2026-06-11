#include <iostream>

using namespace std;

int Cube(int x);

int main() {
    int x, result;
    
    cin >> x ;
    result = Cube(x);
    cout << result << endl;
    
    return 0;
}

int Cube(int x) {
    return x*x*x;
}