#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;

    vector<int> d(N);
    rep(i, N) cin >> d.at(i);

    int sum = 0;
    rep(i, N - 1) {
        for(int j = i + 1; j < N; j++) {
            sum += d.at(i) * d.at(j);
        }
    }
    cout << sum << endl;
}