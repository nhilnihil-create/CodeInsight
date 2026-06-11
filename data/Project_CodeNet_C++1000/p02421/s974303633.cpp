#include <iostream>
#include <string>
using namespace std;

int main () {
    int taro, hana = 0;
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        if ( a == b ) {
            taro++;
            hana++;
        } else if ( a > b) {
            taro += 3;
        } else {
            hana += 3;
        }
    }
    cout << taro << " " << hana << endl;
    return 0;
}