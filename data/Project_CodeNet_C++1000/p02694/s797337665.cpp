#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;

    long long y = 100;
    int count = 0;
    while(true) {
        y += y / 100;
        count++;
        if(y >= x) break;
    }

    cout << count << endl;

    return 0;
}    