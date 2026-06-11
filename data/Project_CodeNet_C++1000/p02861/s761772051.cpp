/*
    Problem 15
    https://atcoder.jp/contests/abc145/tasks/abc145_c
*/
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
double dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}
/* main */
int main(){
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    double sum = 0.0;
    double cnt = 0.0;
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    do {
        cnt++;
        for (int i = 0; i < N - 1; i++)
            sum += dist(x[p[i]], y[p[i]], x[p[i+1]], y[p[i+1]]);
    } while (next_permutation(p.begin(), p.end()));
    cout << setprecision(10) << sum / cnt << '\n';
}