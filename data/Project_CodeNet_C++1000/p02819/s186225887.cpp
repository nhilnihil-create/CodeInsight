#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

bool isPrime(int x) {
    bool prime = true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) prime = false;
    }
    return prime;
}

int main() {
    int x;
    cin >> x;

    while(!isPrime(x)) {
        x++;
    }

    cout << x << endl;

    return 0;
}
