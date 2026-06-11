#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> ans(N - 1);
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
                int dist = min(j - i - 1, abs(i - X) + abs(j - Y));
                ans.at(dist)++;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        cout << ans.at(i) << endl;
    }
}