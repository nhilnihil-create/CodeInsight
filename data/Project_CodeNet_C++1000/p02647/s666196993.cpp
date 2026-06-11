#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }

    int cnt = min(50, K);

    rep(i, cnt){
        vector<int> B(N+1);
        rep(j, N){
            int a = A[j];
            int l = max(0, j-a);
            int r = min(N, j+a+1);
            B[l]++;
            B[r]--;
        }
        for (int j = 1; j < N; j++){
            B[j] += B[j-1];
        }
        B.pop_back();
        A = B;
    }

    rep(i, N){
        cout << A[i] << endl;
    }

    return 0;
}