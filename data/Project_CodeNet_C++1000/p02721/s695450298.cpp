#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    auto sub = [&](const string& S) {
        int cur = 0, last = -c - 1;
        vector<int> res(n + 1, 0); // 各マスを区切る線に注目
        for (int i = 0; i < n; i++) {
            if (i - last > c && S[i] == 'o')
                ++cur, last = i;
            res[i + 1] = cur;
        }
        return res;
    };

    const auto& left = sub(s);
    string t = s;
    reverse(t.begin(), t.end());
    const auto& right = sub(t);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x')
            continue;
        if (left[i] + right[n - i - 1] < k)
            cout << i + 1 << endl;
    }
}