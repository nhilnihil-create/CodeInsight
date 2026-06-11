#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    rep(i, N){
        cin >> A[i] >> B[i];
    }

    if(N % 2 == 1){
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int x = N / 2;
        cout << B[x] - A[x] + 1 << endl;
    } else {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int x1 = N / 2 - 1;
        int x2 = N / 2;
        int mi = A[x1] + A[x2];
        int ma = B[x1] + B[x2];
        cout << ma - mi + 1 << endl;
    }

    return 0;
}