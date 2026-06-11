#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X;
    cin >> X;
    long long yokin = 100;
    int t = 0;
    while (yokin < X) {
        t++;
        yokin += yokin/100;
    }
    cout << t << endl;

}