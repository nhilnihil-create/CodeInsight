#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int ans = 0;
    int now = 0;

    for(int i = 0; i < N - 1; i++) {
        if(A.at(i) >= A.at(i + 1)) {
            now++;
            ans = max(ans, now);
        } else {
            now = 0;
        }
    }
    cout << ans << endl;
    return 0;
}