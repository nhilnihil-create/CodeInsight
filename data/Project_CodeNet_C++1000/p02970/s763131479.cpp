#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, D; cin >> N >> D;
    int d = D*2 + 1;
    int ans = (N-1)/d + 1;
    cout << ans << endl;

    return 0;
}