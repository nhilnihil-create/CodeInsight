#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    rep(i,n) {
        if ((1 <= i+1 && i+1 <= 9) || (100 <= i+1 && i+1 <= 999) || (10000 <= i+1 && i+1 <= 99999)) ans++;
    }
    cout << ans << endl;
}
