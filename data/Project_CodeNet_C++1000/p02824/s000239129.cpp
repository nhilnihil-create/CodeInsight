#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int N, M, V, P;
vector<ll> A;

bool check(int idx) {
    // cout << "# idx : " << idx << " , A[idx] : " << A[idx] << endl;
    ll big = 0, les = 0;
    REP(i, 0, N) {
        if (A[idx] + M < A[i]) big++;
        if (A[idx] >= A[i]) les++;
    }

    if (big >= P) return false;
    ll rem = V - (P - 1) - les;
    // cout << "--> big : " << big << " les : " << les << " rem : " << rem << endl;
    rem *= M;
    for (int i = idx + 1; i < N - P + 1; i++) {
        rem -= A[idx] + M - A[i];
    }    

    if (rem < 1) return true;
    else return false;
}

int main() {
    cin >> N >> M >> V >> P;
    A.resize(N); 
    REP(i, 0, N) cin >> A[i];
    sort(ALL(A));

    int ng = -1, ok = N;
    while (ok - ng > 1) {
        int mid = ng + (ok - ng) / 2;
        if (check(mid)) ok = mid;
        else ng = mid;
    }

    cout << N - ok << endl;
    return 0;
}