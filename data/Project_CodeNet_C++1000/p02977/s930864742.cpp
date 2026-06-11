#include<bits/stdc++.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound


signed main() {
    int N;
    cin >> N;
    int a = 1;
    rep(i, 20) {
        if (N == a) {
            cout << "No" << endl;
            return 0;
        }
        a *= 2;
    }
    if (N % 2 == 1) {
        cout << "Yes" << endl;
        rep(i, N / 2) {
            int a = 2 * i + 2;
            int b = 2 * i + 3;
            cout << 1 << " " << a << endl;
            cout << a << " " << b << endl;
            cout << 1 << " " << b + N << endl;
            cout << b + N << " " << a + N << endl;
        }
        cout << 3 << " " << 1 + N << endl;
    } else {
        cout << "Yes" << endl;
        rep(i, (N - 1) / 2) {
            int a = 2 * i + 2;
            int b = 2 * i + 3;
            cout << 1 << " " << a << endl;
            cout << a << " " << b << endl;
            cout << 1 << " " << b + N << endl;
            cout << b + N << " " << a + N << endl;
        }
        cout << 3 << " " << 1 + N << endl;
        //Nと2Nの配置
        int n2 = N & -N;
        int n1 = N - n2;
        cout << n1 << " " << N << endl;
        cout << n2 + 1 + N << " " << 2 * N << endl;
    }
    return 0;
}
