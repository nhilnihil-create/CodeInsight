#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N, K;
    cin >> N >> K;

    int cnt = 0;
    rep(i, N)
    {
        int h;
        cin >> h;
        if (h >= K) cnt++;
    }

    cout << cnt << endl;

    return 0;
}