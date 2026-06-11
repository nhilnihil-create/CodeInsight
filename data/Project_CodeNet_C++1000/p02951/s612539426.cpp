#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a;
    long long b;
    long long c;
    cin >> a >> b >> c;
    long long sum = (b + c);
    if (sum > a) {
        cout << (sum - a) << endl;
    }
    else {
        cout << "0" << endl;
    }
    return 0;
}
