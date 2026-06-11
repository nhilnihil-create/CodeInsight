/*
    Problem 98
    https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int mod = 1000000007;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> cnt(N, 0);
    cnt[0] = 3;
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ans *= cnt[a[i]]--;
        ans %= mod;
        cnt[a[i]+1]++;
    }
    cout << ans << '\n';
}