#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t X, sav = 100L;
    int cnt = 0;
    cin >> X;
    while (sav < X) {
        sav += sav / 100;
        cnt++;
    }
    cout << cnt <<endl;
}
