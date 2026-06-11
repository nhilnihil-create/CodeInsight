#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N, M; cin >> N >> M;
    ll N2 = pow(2, N);
    vector<vector<ll>> DP(M+1, vector<ll>(N2));
    for(int i = 0; i < M+1; i++){
        for(int j = 0; j < N2; j++){
            if(j == 0) DP[i][j] = 0;
            else DP[i][j] = 1e9;
        }
    }
    for(int i = 1; i < M+1; i++){
        ll a, b; cin >> a >> b;
        bitset<12> C;
        for(int j = 0; j < b; j++) {
            ll c; cin >> c; c--;C.set(c);
        }
        for(int j = 0; j < N2; j++){
            bitset<12> B = j;
            ll temp = (C|B).to_ullong();
            DP[i][j] = min(DP[i-1][j], DP[i][j]); // unused
            DP[i][temp] = min(DP[i][temp], DP[i-1][j]+a); // used
            
        }
    }
    if(DP[M][N2-1] == 1e9) cout << -1 << endl;
    else cout << DP[M][N2-1] << endl;

}