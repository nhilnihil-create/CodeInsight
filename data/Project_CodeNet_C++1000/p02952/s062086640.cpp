#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int getketa(int num) {
    int keta = 0;
    while(num) {
        keta += 1;
        num /= 10;
    }
    return keta;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    rep(i, n) {
        if(getketa(i + 1) % 2 == 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
