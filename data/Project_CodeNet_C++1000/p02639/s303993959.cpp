#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, i;
    for (i = 0; i < 5; i++) {
        cin >> num;
        if (num == 0) {
            break;
        }
    }
    cout << i + 1 << endl;
}