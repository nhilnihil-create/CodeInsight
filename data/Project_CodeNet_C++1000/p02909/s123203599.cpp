#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    char C;
    C = S[0];

    if (C == 'S') {
        cout << "Cloudy" << endl;
        return 0;
    } else if (C == 'C') {
        cout << "Rainy" << endl;
        return 0;
    } else {
        cout << "Sunny" << endl;
        return 0;
    }

}