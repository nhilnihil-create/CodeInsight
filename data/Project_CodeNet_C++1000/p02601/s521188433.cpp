#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    for(int i=0; i<k; i++) c *= 2;
    for(int i=0; i<k; i++) {
        if(a < b && b < c) {
            cout << "Yes" << endl;
            return 0;
        }
        c /= 2;
        b *= 2;
    }
    cout << "No" << endl;
}