#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N;
    cin >> N;
    for (ll i = sqrt(N+1); i > 0; --i) {
        if (N % i == 0) {
            cout << i + N / i - 2 << endl;
            return 0;
        }
    }
}
