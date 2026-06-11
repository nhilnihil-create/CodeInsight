#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    long n;
    cin >> n;
    vector<long> h(n);
    int m = 0;
    int c = 0;
    cin >> h[0];
    rep(i, n - 1) {
        cin >> h[i + 1];
        if(h[i + 1] > h[i])
            m = max(m, c), c = 0;
        else
            c++;
    }
    m = max(m, c);

    cout << m << endl;
}