#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int K = 0;
    int N = 0;
    cin >> K;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    int ans = abs(K + A.at(0) - A.at(N - 1));
    for(int i = 0; i < N-1; i++) {
        ans = max(ans,abs(A.at(i) - A.at(i+1)));
    }
    cout << K - ans << endl;

    return 0;
} 