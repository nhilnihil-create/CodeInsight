#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    //cout << n / 2-1 << endl;
    int ans = 0;
    int tmp = n%2? n/2+1 : n/2;
    for (int i = 1; i < tmp; i++)
        ans++;
    cout << ans <<endl;
    return 0;
}