#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int N, ans=0;

    cin >> N;

    vector<int> A(N), B(N), C(N-1);

    rep(i,N) {
        cin >> A[i];
    }

    rep(i,N) {
        cin >> B[i];
    }

    rep(i,N-1) {
        cin >> C[i];
    }

    rep(i,N) {
        ans += B[A[i]-1];
        if(A[i]-1==A[i-1]) {
            ans += C[A[i]-2];
        }
    }

    cout << ans << endl;

    return 0;
    
}