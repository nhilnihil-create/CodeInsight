#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N ;i++) cin >> a[i];

    vector<int> sum(N+1);
    for (; K > 0; K--) {
        // imos
        fill(sum.begin(), sum.end(), 0);
        for (int i = 0; i < N; i++) {
            int l = max(0, i - a[i]);
            int r = min(N, i + a[i] + 1);
            sum[l]++, sum[r]--;
        }
        for (int i = 0; i < N; i++) {
            sum[i+1] += sum[i];
            a[i] = sum[i];
        }
        // 収束判定
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (a[i] != N) flag = true;
        }
        if (!flag) {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}
