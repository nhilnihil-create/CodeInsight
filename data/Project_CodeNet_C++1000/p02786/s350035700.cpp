#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h;
    cin >> h;

    int d;
    for (d = 0; h > 1; d++)
        h /= 2;
    
    cout << (long long) (pow(2, ++d) - 1) << endl;
}