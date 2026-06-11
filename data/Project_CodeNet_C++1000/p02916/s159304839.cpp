#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N), C(N-1);
    rep(i, N){
        cin >> A[i];
        A[i]--;
    }
    rep(i, N){
        cin >> B[i];
    }
    rep(i, N-1){
        cin >> C[i];
    }

    int ans = 0;
    int befo = -2;

    rep(i, N){
        ans += B[A[i]];
        if(A[i] == befo+1){
            ans += C[befo];
        }
        befo = A[i];
    }

    cout << ans << endl;

    return 0;
}
