#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            int a;
            cin >> a;
            mp[a]++;
        }
        
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i] == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}