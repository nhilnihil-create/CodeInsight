#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pn;
    cin >> pn;
    int count = 1;
    for (int i = 1; i < n; i++) {
        int pnn;
        cin >> pnn;
        if (pn > pnn) {
            pn = pnn;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}