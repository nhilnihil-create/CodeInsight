#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N + 1,100010);
    for(int i = 0; i < N - 1; i++) {
        cin >> A.at(i + 1);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += min(A.at(i), A.at(i + 1));
    }

    cout << ans << endl;



    return 0;
}