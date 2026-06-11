#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    ll r=0, g=0, b=0;
    cin >> N;
    string S;
    cin >> S;
    rep(i, N) {
        if(S[i] == 'R') {
            r++;
        } else if(S[i] == 'G') {
            g++;
        } else if(S[i] == 'B') {
            b++;
        }
    }
    ll all, cnt = 0;
    all = r * g * b;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(S[i] == S[j])
                continue;
            int k = j * 2 - i;
            if(k >= N || S[k] == S[i] || S[k] == S[j])
                continue;
            ++cnt;
        }
    }
    // cout << cnt << endl;
    cout << all - cnt << endl;
}
