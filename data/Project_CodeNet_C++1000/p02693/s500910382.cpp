#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, a, b;
    cin >> k >> a >> b;
    int flag = 0;
    for (int i = a; i <= b; i++) {
        if (i%k == 0) {
            flag = 1;
        }
    }
    flag == 1 ? cout << "OK" : cout << "NG";
    return 0;
}