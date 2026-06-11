#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    vector<int> H;
    vector<int> ma;
    cin >> N >> M;
    H.push_back(0);
    ma.push_back(0);
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        H.push_back(n);
        ma.push_back(0);
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ma.at(a) = max(ma.at(a), H.at(b));
        ma.at(b) = max(ma.at(b), H.at(a));
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += H.at(i) > ma.at(i);
    }
    cout << ans << endl;
}
