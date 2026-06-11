#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X.at(i);
        Y.at(i) = X.at(i);
    }
    sort(Y.begin(), Y.end(), greater<int>());

    int ans = 1e9;
    for (int i = 1; i <= Y.at(0); i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += pow(X.at(j) - i, 2);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}