#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i, N) cin >> h.at(i);

    int count = 0;
    rep(i, N) {
        if (h.at(i) >= K) count++;
    }

    cout << count << endl;
    
    return 0;
}
