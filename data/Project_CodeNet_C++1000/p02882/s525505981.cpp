/*
    Problem 91
    https://atcoder.jp/contests/abc144/tasks/abc144_d
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
/* main */
int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double y = 2 * x / (a * b * b);
    double z = (a * a * a) / (2 * (a * a * b - x));
    if (a * a * b / 2 >= x)
        cout << fixed << setprecision(9) << 90 - atan(y) * 180 / pi << '\n';
    else
        cout << fixed << setprecision(9) << 90 - atan(z) * 180 / pi << '\n';
}