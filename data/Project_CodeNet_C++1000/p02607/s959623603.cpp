#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    int ans = 0;
    rep(i, n) {
        if (i % 2 == 0 && a.at(i) % 2 == 1) ans++;
    }
    cout << ans << endl;
}