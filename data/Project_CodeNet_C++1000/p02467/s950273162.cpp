/*
    Problem 68
    https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A
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
map<int, int> primeFactrization(int x) {
    map<int, int> factor;
    int n = x;
    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            factor[i]++;
            n /= i;
        }
    }
    if (n != 1) factor[n]++;
    return factor;
}
/* main */
int main(){
    int x;
    cin >> x;
    map<int, int> factor = primeFactrization(x);
    cout << x << ":";
    for (auto f : factor)
        for (int i = 0; i < f.second; i++)
            cout << ' ' << f.first;
    cout << '\n';
}
