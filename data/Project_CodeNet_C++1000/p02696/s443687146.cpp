#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    ll N, A, B, ans;

    cin >> A >> B >> N;

    if(N<B) {
        ans = floor(A*N/B) - A*floor(N/B);
    } else {
        ans = floor(A*(B-1)/B) - A*floor((B-1)/B);
    }

    cout << ans << endl;

    return 0;
    
}