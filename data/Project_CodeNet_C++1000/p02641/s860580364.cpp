#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define erep(i, n) for (int i = 0; i <= (n); i++)
#define erep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
    }
    int ans = 0;
    rep(i, 100) {
        int flag = 0;
        int tmp = 0;
        tmp = x - i;
        rep(i, n) {
            if (tmp == p[i]) flag = 1;
        }
        if (flag == 0) {
            ans = tmp;
            break;
        }
        flag = 0;
        tmp = x + i;
        rep(i, n){
            if (tmp == p[i]) flag = 1;
        }
        if (flag == 0) {
            ans = tmp;
            break;
        }
    }
    cout << ans << endl;
}