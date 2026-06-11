#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans;
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N), F(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++) {
        cin >> F.at(i);
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<int>());
    long long X = 0;
    for(int i = 0; i < N; i++) {
        long long Y = A.at(i) * F.at(i);
        X = max(X, Y);
    }
    long long l = 0, r = X;
    while(l < r) {
        long long M = (l + r) / 2;
        long long Count = 0;
        for(int i = 0; i < N; i++) {
            if(M < A.at(i) * F.at(i))
                Count += A.at(i) - M / F.at(i);
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
