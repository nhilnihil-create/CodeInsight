#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    rep(i, m) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << max(-1, n - sum) << endl;
}
