/*
    Problem 95
    https://atcoder.jp/contests/abc149/tasks/abc149_b
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll A, B, K;
    cin >> A >> B >> K;
    ll tmp = A;
    A = max(A - K, 0LL);
    K = max(K - tmp, 0LL);
    B = max(B - K, 0LL);
    cout << A << ' ' << B << '\n';
}
