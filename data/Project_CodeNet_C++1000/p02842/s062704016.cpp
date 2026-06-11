#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int m = ceil(n/1.08);
    if (floor(m*1.08)==n) {
        cout << m << endl;
    } else {
        cout<< ":(" << endl;
    }
}