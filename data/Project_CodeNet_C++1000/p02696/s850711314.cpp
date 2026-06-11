#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, N;
    cin >> A >> B >> N;
    long long x;
    if (B > N) x = N;
    else x = B - 1;
    cout << A * x / B - A * (x / B) << endl;
}