#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    int N,K;
    cin >> N >> K;

    vector<vector<long long> > C(N+1,vector<long long>(N+1,0));

    for(int i=0; i<=N; ++i) {
        C[i][0]=1;
        C[i][i]=1;
    }

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<i; ++j) {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }

    long long ans = 0;
    for (int i=1; i<=K; i++) {
        ans = (C[N-K+1][i]*C[K-1][i-1])%MOD;
        cout << ans << endl;
    }

    return 0;
}

