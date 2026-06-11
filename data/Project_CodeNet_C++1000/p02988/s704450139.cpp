#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    int cnt = 0;
    rep(i,n-2) {
        if ((a[i] < a[i+1] && a[i+1] < a[i+2]) || (a[i] > a[i+1] && a[i+1] > a[i+2])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
