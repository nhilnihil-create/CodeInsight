#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int change;
    int sen;

    sen = ((N-1) / 1000) + 1;
    change = 1000 * sen - N;

    cout << change << endl;

    return 0;
}
