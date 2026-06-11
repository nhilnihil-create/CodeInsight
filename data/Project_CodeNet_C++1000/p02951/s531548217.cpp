#include <iostream>
using namespace std;
int main(){
    int a, b, c , d;
    cin >> a >> b >> c;
    d = (b + c) - a;
    if (d < 0) cout << "0" << endl;
    else cout << d << endl;
}