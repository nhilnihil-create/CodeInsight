/*
    Problem 99
    https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d
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
    int M;
    cin >> M;
    vector<ll> d(M), c(M);
    for (int i = 0; i < M; i++) cin >> d[i] >> c[i];
    ll D = 0;
    ll S = 0;
    for (int i = 0; i < M; i++) {
        D += c[i];
        S += d[i] * c[i];
    }

    cout << (D - 1) + (S - 1) / 9 << '\n';
}