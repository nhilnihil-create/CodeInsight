#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x;
    cin >> x;
    long long a = 0;
    long long b = 0; 
    while (pow(a,5) - pow(a-1,5) <= x) {
        b = -a;
        while (b < a) {
            if (pow(a,5) - pow(b,5) == x) {
                cout << a << " " << b;
                return 0;
            }
            b++;
        }
        a++;
    }
}
