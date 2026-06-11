#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N,M,X; cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N,vector<int>(M));
    for (int i=0; i<N; ++i){
        cin >> C[i];
        for (int j=0; j<M; ++j) cin >> A[i][j];
    }    
    ll res = 1e9;
    for (int bit=0; bit<(1<<N); ++bit){
        bool can = true;
        ll cost = 0;
        vector<int> B(M, 0);
        for (int i=0; i<N; ++i){
            if (bit & (1<<i)) {
                for (int j=0; j<M; ++j) B[j] += A[i][j];
                cost += C[i];
            }
        }
        for (int j=0; j<M; ++j) if (B[j]<X) can = false;
        if (can) res = min(res, cost);
    }
    if (res==(ll)1e9) {
        cout << "-1"<< endl;
    }else{
        cout << res << endl;    }
    
    return 0;
}