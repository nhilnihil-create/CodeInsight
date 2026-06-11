#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long m = 1e12;

int main() {
    long long n, ans;
    cin >> n;
    for(int i = sqrt(n); i > 0; --i)
        if(n % i == 0) {
            cout << (i + (n / i) - 2) << endl;
            break;
        }
    return 0;
}