#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A;
    double B;
    cin >> A >> B;
    long long B100 = (long long)(B * 100 + 0.001);
    cout << A * B100 / 100 << endl;
}