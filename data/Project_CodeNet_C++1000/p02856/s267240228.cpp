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
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> d(N), c(N);
    for (int i = 0; i < N; i++) cin >> d[i] >> c[i];
    ll digitNum = 0;
    ll digitSum = 0;
    for (int i = 0; i < N; i++) {
        digitNum += c[i];
        digitSum += c[i] * d[i];
    }
    cout << digitNum - 1 + (digitSum - 1) / 9 << '\n';
}
