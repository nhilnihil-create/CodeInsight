#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long S, long long W) {
    if (S <= W) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
}

int main() {
    long long S;
    scanf("%lld", &S);
    long long W;
    scanf("%lld", &W);
    solve(S, W);
    return 0;
}
