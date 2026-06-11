#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num, k, s;
    cin >> num >> k >> s;

    if (s == 1000000000) {
        for (int i = 0; i < k; i++) cout << s << " ";
        for (int i = k; i < num; i++) cout << 1 << " ";
    } else {
        for (int i = 0; i < k; i++) cout << s << " ";
        for (int i = k; i < num; i++) cout << 1000000000 << " ";
    }
}