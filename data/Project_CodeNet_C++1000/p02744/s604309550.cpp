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

void dfs(int n, int k, string s) // 現在k種類の文字を使った
{
    if (n == 0) {
        cout << s << endl;
        return;
    }

    for (int i = 0; i < k + 1; i++) {
        if (i == k) {
            dfs(n - 1, k + 1, s + (char)('a' + i));
        } else {
            dfs(n - 1, k, s + (char)('a' + i));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string s = "";
    dfs(n, 0, s);
    return 0;
}