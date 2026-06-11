#include <bits/stdc++.h>
using namespace std;

int m;
long nDigit = 0, sumDigit = 0; 

int main() {
    cin >> m;
    for (int i = 0; i < m; i++){
        long d, c;
        cin >> d >> c;
        nDigit += c;
        sumDigit += d*c;
    }
    
    cout << nDigit - 1 + (sumDigit - 1) / 9 << endl;

    return 0;
}
