#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define mod 1000000007
#define ps(x,noOfDecimal) fixed<<setprecision(noOfDecimal)<<x

using namespace std;
// int d[10000001];

signed main()
{
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    std::ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        set<int> arr;
        for (int i = 1; i <= sqrt(min(a, b)); i++) {
            if (a % i == 0) {
                if (b % i == 0) {
                    arr.insert(i);
                }
                int x = a / i;
                if (b % x == 0) {
                    arr.insert(x);
                }
            }
            else if (b % i == 0) {
                if (a % i == 0) {
                    arr.insert(i);
                }
                int x = b / i;
                if (a % x == 0) {
                    arr.insert(x);
                }
            }
        }
        int cnt = 0;
        unordered_map<int, int> d;
        vector<int> ans;
        for (auto i : arr) {
            ans.push_back(i);
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != -1) cnt++;
            if (ans[i] > 1)
                for (int j = i + 1; j < ans.size(); j++) {
                    if (ans[j] % ans[i] == 0) ans[j] = -1;
                }
        }
        cout << cnt;
    }
    return 0;
}