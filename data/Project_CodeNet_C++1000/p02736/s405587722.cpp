#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

vector<int> evencnt;
bool iseven(int n, int r) {
    int tmp = evencnt[n] - evencnt[r] - evencnt[n - r];
    return tmp > 0;
}

int solve(string &a, bool flag = false) {
    int N = a.length();
    bool iszero = false;
    bool isone = false;
    for (int i = 0; i < N; ++i) {
        int num = a[i] - '0';
        if (num & 1)
            iszero = true;
        if ((num & 1) && !iseven(N - 1, i))
            isone ^= 1;
    }

    if (isone)
        return 1;
    else if (iszero || flag)
        return 0;
    else {
        for (int i = 0; i < N; ++i)
            if (a[i] == '2')
                a[i]--;
        return solve(a, true) << 1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string a;
    cin >> N >> a;
    for (int i = 0; i < N; ++i)
        a[i]--;

    evencnt.resize(N);
    evencnt[0] = 0;
    for (int i = 1; i < N; ++i) {
        evencnt[i] = evencnt[i - 1];
        if (!(i & 1))
            evencnt[i] += evencnt[i >> 1] - evencnt[(i >> 1) - 1] + 1;
    }

    cout << solve(a) << endl;

    return 0;
}
