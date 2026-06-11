#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, T, S;
    cin >> D >> T >> S;
    double time = (double)D / S;
    if(time <= T) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}