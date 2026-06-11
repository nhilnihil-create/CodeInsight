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

const int MAX = 2e5 + 5;

int main() {
    IO;
    ll n, a, have = 0, c = 1000, prev;
    cin >> n >> prev;
    For(i, 1, n) {
        cin >> a;
        if (a > prev) {
            have = c / prev, c %= prev;
            c += have * a;
        }
        prev = a;
    }
    printf("%lld\n", c);
    return 0;
}