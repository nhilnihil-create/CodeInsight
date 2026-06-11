#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

#define N 1000000007

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> p(n);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++)
        cin >> c[i];

    ll max_point = -10e16;

    for (int i = 0; i < n; i++) {
        int cur = i;
        ll point = 0;
        ll loop_size = 0;

        while (true) {
            cur = p[cur];
            point += c[cur];
            loop_size++;
            if (cur == i) break;
        }

        ll point_sub = 0;
        for (int j = 0; j < min(k, loop_size); j++) {
            cur = p[cur];
            point_sub += c[cur];
            max_point = max(max_point,
                    max(0ll, point) * (ll)((k - j - 1) / loop_size) + point_sub);
        }
    }
    cout << max_point << endl;
    return 0;
}