#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // 累積和、答えを決め打って二分探索
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        int x;
        cin >> x;
        A[--x]++;
    }
    sort(A.begin(), A.end()); // 0はそのまま無視
    vector<int> Acum(N+1);
    rep(i, N) Acum[i+1] = Acum[i] + A[i];
    for (int k = 1; k <= N; k++) {
        ll ok = 0; ll ng = N+1;
        while (abs(ng - ok) > 1) {
            ll mid = (ok + ng) / 2;
            bool bl = [&] {
                auto ind = lower_bound(A.begin(), A.end(), mid) - A.begin();
                int temp = Acum[ind] + mid * (N - ind);
                return (temp >= mid * k);
            }();
            if (bl) ok = mid;
            else ng = mid;
        }
        printf("%d\n", ok);
    }
    return 0;
}
