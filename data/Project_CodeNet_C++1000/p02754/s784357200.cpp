#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long t = n / (a + b);
    long long last = n % (a + b);
    long long exb = last;
    if (exb > a) exb = a;
    cout << t * a + exb << endl;

}