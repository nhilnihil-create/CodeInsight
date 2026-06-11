#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000;
const int INF = 1e6;

int n;
string s;

bool C(int x) {
    string M[MAX];
    if (x > n/2) return false;
    for (int i = 0; i+x <= n; i++) {
        M[i] = s.substr(i, x);
    }
    for (int i = 0; i+x+x <= n; i++) {
        for (int j = i+x; j+x <= n; j++) {
            if (M[i] == M[j]) return true;
        }
    }
    return false;
}

void solve() {
    int lb = 0, ub = INF;

    while (ub-lb > 1) {
        int mid = (lb+ub)/2;
        if (C(mid)) lb = mid;
        else ub = mid;
    }

    printf("%d\n", lb);
}

int main() {
    cin >> n >> s;

    solve();
}