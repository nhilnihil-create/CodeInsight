#include <iostream>
using namespace std;

int main(){
    int a, b;
    int c, d;

    cin >> a >> b;
    cin >> c >> d;

    int y = (c+b-1) / b;
    int x = (a+d-1) / d;

    cout << (x < y ? "No" : "Yes") << endl;
}
