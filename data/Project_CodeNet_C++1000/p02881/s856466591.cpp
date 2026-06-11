#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin >> N;
    ll m, j, len;
    for(int i = 1; i <= sqrt(N); i++) {
        if(N % i == 0) {
            j = N / i;
            len = i + j - 2;
            m = min(m, len);
        }
    }
    cout << m << endl;
    return 0;
}
