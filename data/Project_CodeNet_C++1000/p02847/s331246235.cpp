#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;

    map<string, int> table {
        {"SUN", 0},
        {"MON", 1},
        {"TUE", 2},
        {"WED", 3},
        {"THU", 4},
        {"FRI", 5},
        {"SAT", 6}
    };

    cout << 7 - table[S] << endl;

    return 0;
}