#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, V, P;
vector<ll>A;

bool C1(ll x){
    if (A[P-1] > A[x] + M) return false;
    ll ex = (V - P) * M;
    if (ex <= 0) return true;
    for (int i = P - 1; i < N; ++i) {
        if(i == x) continue;
        ex -= min(M, A[x] + M - A[i]);
    }
    if (ex <= 0) return true;
    else return false;
}

// 開区間と判定関数を引数にして条件を満たす境界値を返す
ll BiSearch(ll ok, ll ng, function<bool(ll)> C){
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (C(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin >> N >> M >> V >> P;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());
    cout << BiSearch(P-1, N, C1) + 1 << "\n";
    return 0;
}