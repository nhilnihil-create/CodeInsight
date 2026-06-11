#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int sum = 0;
    rep(i, N) sum += A[i];
    if (sum >= H)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}