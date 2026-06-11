#include <algorithm>
#include <cmath>
#include <cstring>  // memset()
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define For(i, a, b) for (int i = (int)(a), sz = (int)(b); i < sz; i++)
#define rFor(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

const int MAX = 1e5 + 5;

int main() {
    IO;
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    For(i, 0, n) cin >> v[i];
    sort(all(v));
    For(i, 0, k) ans += v[i];
    printf("%d\n", ans);
    return 0;
}