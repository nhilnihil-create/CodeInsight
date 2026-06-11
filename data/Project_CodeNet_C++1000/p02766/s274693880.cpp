#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<int(n); i++)

int main() {
    int n,k; cin >> n >> k;
    int ans = 0;
    for (int i=1;;i++) {
        if (n < pow(k,i)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}