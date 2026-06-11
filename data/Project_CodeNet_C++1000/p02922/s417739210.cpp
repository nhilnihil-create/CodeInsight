#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 1;

    int c = 0;
    while (cnt < b) {
        c++;
        cnt--;
        cnt += a;
    }
    cout << c;
}