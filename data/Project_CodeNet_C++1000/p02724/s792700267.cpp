#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int count = 0;
    while(true) {
        if(x < 500) break;
        x -= 500;
        count += 1000;
    }

    while(true) {
        if(x < 5) break;
        x -= 5;
        count += 5;
    }

    cout << count << endl;

    return 0;
}