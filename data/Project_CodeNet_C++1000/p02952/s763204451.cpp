#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string str = to_string(i);
        int len = str.size();
        if(len % 2 == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}
