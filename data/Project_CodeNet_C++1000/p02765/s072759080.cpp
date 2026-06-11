#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, r, s;
    cin >> n >> r;
    if(n < 10) {
        s = 100 * (10 - n);
    } else {
        cout << r;
        return 0;
    } 
    cout << r + s;
    return 0;
}

