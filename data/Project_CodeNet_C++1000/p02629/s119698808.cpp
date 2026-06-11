#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N) {
    string ans;
    N--;
    do {
        ans += ('a' + (N % 26));
        N /= 26;
        N--;
    } while(0 <= N);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
