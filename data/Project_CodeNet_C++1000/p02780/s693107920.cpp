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
double mean(double m) { return (m+1) / 2; }
/* main */
int main(){
    int N;
    double K;
    cin >> N >> K;
    vector<double> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) a[i] = mean(a[i]);
    vector<double> sum(N+1);
    for (int i = 0; i < N; i++) sum[i+1] = sum[i] + a[i];
    double mx = 0.0;
    for (int i = 0; i <= N - K; i++) {
        mx = max(mx, sum[i+K] - sum[i]);
    }
    cout << fixed << setprecision(8) << mx << '\n';

}
