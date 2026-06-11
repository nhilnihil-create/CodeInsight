#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int g = b * 2;
    if(a > g){
        cout << a - g;
    } else{
        cout << "0";
    }
    return 0;
}