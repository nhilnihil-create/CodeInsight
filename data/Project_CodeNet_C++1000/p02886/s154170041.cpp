#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int N, ans=0;

    cin >> N;

    vector<int> d(N);

    rep(i, N) {
        cin >> d[i];
        if(i>0) {
            rep(j, i) {
                ans += d[i] * d[j];
            }
        }
    }

    cout << ans << endl;

    return 0;
    
}