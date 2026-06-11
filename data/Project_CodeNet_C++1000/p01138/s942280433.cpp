/*
    Problem 82
    https://onlinejudge.u-aizu.ac.jp/problems/2013
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
const int MAX = 24*3600+2;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<int> T(MAX);
/* function */
int stringToSecond(string S) {
    int t = stoi(S.substr(0, 2)) * 3600 + stoi(S.substr(3, 2)) * 60 + stoi(S.substr(6, 2));
    return t;
}
void solve(int N) {
    for (int i = 0; i <= MAX; i++) T[i] = 0;
    for (int i = 0; i < N; i++) {
        string st; cin >> st;
        string gl; cin >> gl;
        T[stringToSecond(st)]++;
        T[stringToSecond(gl)]--;
    }
    int ans = 0;
    for (int i = 0; i <= MAX; i++) {
        T[i+1] += T[i];
        ans = max(ans, T[i]);
    }
    cout << ans << '\n';
}
/* main */
int main(){
    while (1) {
        int N;
        cin >> N;
        if (N == 0) return 0;
        solve(N);
    }
}
