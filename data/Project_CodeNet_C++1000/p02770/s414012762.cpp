#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, q;
    cin >> k >> q;

    vector<int> d(k);
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }

    vector<int> a(k + 1);
    for (int h = 0; h < q; h++) {
        int n, x, m;
        cin >> n >> x >> m;
        n--;
        x %= m;

        int r = 0;

        a[0] = x;
        int c = k;
        for (int i = 0; i < k; i++) {
            a[i + 1] = (a[i] + d[i]) % m;
            if (a[i] == a[i + 1]) c--;
        }

        ll s = 0;
        for (int i = 0; i < k; i++) {
            s += d[i] % m;
        }

        ll a1 = x + s * (n / k);
        int a2 = a1 % m;
        r += c * (n / k) - a1 / m;

        a[0] = a2;
        for (int i = 0; i < n % k; i++) {
            a[i + 1] = (a[i] + d[i]) % m;
            if (a[i] < a[i + 1]) r++;
        }

        //int y = n % k; n -= y;
        //a[0] = x % m;
        //for (int i = 0; i <= y; i++) {
        //    a[i + 1] = (a[i] + d[i]) % m;
        //    if (a[i] < a[i + 1]) r++;
        //}

        //a[0] = a[y] % m;
        //int z = k;
        //for (int i = 0; i < k; i++) {
        //    int i1 = i + y; if (i1 >= k) i1 -= k;
        //    a[i + 1] = (a[i] + d[i1]) % m;
        //    if (a[i] == a[i + 1]) z--;
        //}

        //ll s1 = s * (n / k);
        //int z2 = z * (n / k);
        //int sm = s1 % m;
        //r += z2 - s1 / m;
        //if (a[0] < sm) r--;

        //for (int i = 0; i < k; i++) {
        //    int d = a[i + 1] - a[i];
        //    if (d < 0) d += m;
        //    if (d == 0) {
        //        b0[i] = b1[i] = 0;
        //    } else {
        //        b0[i] = -a[i]; if (b0[i] < 0) b0[i] += m;
        //        b1[i] = b0[i] + (m - d);
        //    }
        //}
        //int o = 0, l = a[k] - a[0]; if (l < 0) l += m;
        //for (int j = 0; j < n; j += k) {
        //    
        //    o += l; if (o < 0) o += m;
        //}

        cout << r << '\n';
    }

    //mがでかいので厄介
    //k個のペアそれぞれについて右が大きくなるオフセットの範囲を求める
    //kが小さいときのこと忘れてた

    return 0;
}