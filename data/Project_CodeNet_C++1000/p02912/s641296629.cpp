#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int> A;
    rep(i, N) {
        int a;
        cin >> a;
        A.push(a);
    }
    int odd = 0;
    rep(i, M) {
        int m = A.top();
        if(m%2==1) {
            ++odd;
        }
        m /= 2;
        A.pop();
        A.push(m);
    }
    ll ans = 0;
    rep(i, N) {
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;
    return 0;
}