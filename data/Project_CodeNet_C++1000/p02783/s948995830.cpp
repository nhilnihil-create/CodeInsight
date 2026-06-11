#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, A;
    cin >> H >> A;
    int i = 1;

    while (H > A*i) {
        i++;
    }

    cout << i;
}