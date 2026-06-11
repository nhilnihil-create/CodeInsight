#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n) cin >> a[i+1];

    vector<int> box(n+1, 0);
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        for (int j = 2; i * j <= n; j++) {
            cnt += box[i * j];
        }
        if ((cnt % 2) != a[i]) {
            box[i] = 1;
        }
    }

    int m = 0;
    vector<int> b;
    rep(i, n) {
        if (box[i + 1] == 1) {
            m++;
            b.push_back(i + 1);
        }
    }

    cout << m << endl;
    rep(i, m) {
        cout << b[i] << endl;
    }
    return 0;
}
