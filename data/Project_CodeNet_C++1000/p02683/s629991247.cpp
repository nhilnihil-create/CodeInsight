#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1001001001

void solve(ll N, ll M, ll X, vector<ll> C, vector<vector<ll> > A){
    int ans = INF;
    for (int i = 0; i < (1<<N); i++)
    {
        int cost = 0;
        vector<int> d(M, 0);
        for(int j = 0; j < N; j++){
            if(i>>j&1){
                cost += C[j];
                for(int k = 0; k < M; k++) d[k] += A[j][k];
            }
        }
        bool ok = true;
        for(int j = 0; j < M; j++) if(d[j] < X) ok = false;
        if(ok) ans = min(ans, cost);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return;
}

int main(){
    ll N, M, X;
    cin >> N >> M >> X;
    vector<ll> C(N);
    vector<vector<ll> > A;
    for(ll i = 0; i < N; ++i){
        cin >> C[i];
        vector<ll> temp_a(M);
        for(ll j = 0; j < M; ++j){
            cin >> temp_a[j];
        }
        A.push_back(temp_a);
    }
    solve(N, M, X, C, A);
    return 0;
}
