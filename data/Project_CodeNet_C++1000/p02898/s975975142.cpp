#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int N, K, ans=0;

    cin >> N >> K;

    vector<int> h(N);

    rep(i, N) {
        cin >> h[i];
        if(h[i]>=K) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
    
}