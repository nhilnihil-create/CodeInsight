#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define int long long int
#define repeat(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()

signed main() {
    int n;
    cin >> n;

    int na[200001];
    vector<int> va;
    memset(na, 0, sizeof(int) * 200001);
    repeat(i, n) {
        int a;
        cin >> a;

        ++na[a];
        va.push_back(a);
    }

    int sum = 0;
    repeat(i, n) {
        sum += (na[i + 1] - 1) * na[i + 1] / 2;
    }

    for (auto x: va) {
        int n = na[x];
        cout << sum - n * (n - 1) / 2 + (n - 2) * (n - 1) / 2 << endl;
    }
}