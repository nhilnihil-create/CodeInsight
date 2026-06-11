/*
    Problem 6
    https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
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
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (char i = '0'; i <= '9'; i++) for (char j = '0'; j <= '9'; j++) for (char k = '0'; k <= '9'; k++) {
        vector<char> v{i, j, k};
        int t = 0;
        for (int s = 0; s < N; s++) {
            if (S[s] == v[t]) t++;
            if (t >= 3) {
                ans++;
                // cout << i << j << k << '\n';
                break;
            }
        }
    }
    cout << ans << '\n';
}