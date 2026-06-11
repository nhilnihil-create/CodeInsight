#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans;
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N), F(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++) {
        cin >> F.at(i);
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<int>());
    long long X = 1e12;
    long long l = 0, r = X;
    while(l < r) {
        long long M = (l + r) / 2;
        long long Count = 0;
        for(int i = 0; i < N; i++) {
            Count += max(0LL, A.at(i) - M / F.at(i));
        }
        if(K >= Count)
            r = M;
        else
            l = M + 1;
        // cout << l << " " << r << endl;
    }
    ans = l;

    cout << ans << endl;
}