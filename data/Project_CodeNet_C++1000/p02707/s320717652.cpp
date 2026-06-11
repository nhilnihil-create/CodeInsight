#include <math.h>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count[n] = {};
    for (int i = 0; i < n - 1; i++) {
        int m;
        cin >> m;
        count[m-1]++;
    }
    for (int i = 0; i < n; i++) {
        cout << count[i] << endl;
    }
    return 0;
}