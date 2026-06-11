#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull a, b, n;
    cin >> a >> b >> n;
    n = min(b-1, n);
    cout << (a*n)/b << "\n";
}