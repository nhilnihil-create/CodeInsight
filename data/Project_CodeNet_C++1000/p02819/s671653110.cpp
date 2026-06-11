#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define PMAX 200000

vector<int> eratosthenes (int n) {
    vector<bool> is_prime(n+1);
    rep(i, n) is_prime[i] = true;

    vector<int> p;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*2; j <= n; j += i) {
                is_prime[j] = false;
            } 
            p.emplace_back(i);
        }
    }
    return p;
}

int main()
{
    int x;
    cin >> x;
    for (const auto tmp : eratosthenes(PMAX)) {
        if (tmp >= x ) {
            cout << tmp << endl;
            return 0;
        }
    }
    return 0;
}