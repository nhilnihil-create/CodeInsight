#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long p = n / (a + b); 
    long long q = n % (a + b);

    cout << p * a + min(q, a) << endl;
}