#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll H;
    cin >> H;
    int cnt = 0;
    while (H > 0) {
        H /= 2;
        ++cnt;
    }
    cout << (1LL << cnt) - 1 << endl;
}
