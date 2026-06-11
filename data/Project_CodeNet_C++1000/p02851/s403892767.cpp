#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N,K;
    cin >> N >> K;
    vector<int64_t> A(N+1,0);
    for ( int64_t i = 1; i <= N; ++i){
        int64_t a;
        cin >> a;
        A[i] = a - 1;
    }
    vector<int64_t> S(N+1,0);
    for ( int64_t i = 1; i <= N; ++i){
        S[i] = S[i-1] + A[i];
    }
    
    map<int64_t,int64_t> m;
    m[0] = m[0] + 1;
    int64_t res = 0;
    for ( int64_t i = 1; i <= N; ++i){
        if ( i - K >= 0 ) {
            m[S[i-K]%K] = m[S[i-K]%K] - 1;
        }
        res = res + m[S[i]%K];
        m[S[i]%K] = m[S[i]%K] + 1;
    }
    
    cout << res << endl;
    
    return 0;
}
