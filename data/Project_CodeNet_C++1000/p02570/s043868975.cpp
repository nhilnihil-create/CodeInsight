#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int inf = ~0u >> 1;
typedef pair<int, int> P;
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n)-1; i >= a; --i)
const ll mod = 1e9 + 7;
int main() {
    IO;
    ll d, s, t;
    cin >> d  >> s >> t;
    if (s * t >= d) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}

