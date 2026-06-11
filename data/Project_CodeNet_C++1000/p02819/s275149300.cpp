#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i=2; i*i<=n; ++i){
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int x;
    cin >> x;
    int ans=0;
    for (int i=x; i<=100010;++i) {
        if (isPrime(i) == true) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}