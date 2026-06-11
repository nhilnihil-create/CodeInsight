#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (void){
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if (s == u) {
        cout << a - 1 << " " << b << endl;
    }else if(t == u) {
        cout << a << " " << b - 1 << endl;
    } else {
        cout << a << " " << b << endl;
    }
    return 0;
}