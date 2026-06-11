#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >>n;
    long long ret = (long long)(1 + n) * n / 2 - n;
    cout << setprecision(30) << ret << endl;
    return 0;
}