#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main() {
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    ll area = w * h;
    int count = 0;
    if (w % 2 == 0 && x == w / 2)
        count++;
    if (h % 2 == 0 && y == h / 2)
        count++;
    if (count == 1) {
        printf("%lld %d", area / 2, 0);
        return 0;
    }
    if (count == 2){
        printf("%lld %d", area / 2, 1);
        return 0;
    }
    printf("%.12f %d\n", area / 2.0, 0);
}