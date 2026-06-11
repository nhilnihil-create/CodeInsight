#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int k,a,b; cin >> k >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            cout << "OK\n";
            return 0;
        }
    }
    cout << "NG\n";
}