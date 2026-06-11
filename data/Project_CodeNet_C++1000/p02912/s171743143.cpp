#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    int N, M;
    cin >> N >> M;

    priority_queue<double> que;
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        que.emplace(static_cast<double>(a));
    }

    for (int i = 0; i < M; ++i) {
        double a = que.top();
        que.pop();

        a /= 2;

        que.emplace(a);
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        double a = que.top();
        que.pop();

        ans += static_cast<ll>(a);
    }

    cout << ans << endl;

    return 0;
}
