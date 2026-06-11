#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int N;  ll K, S = 0;   cin >> N >> K;
    vector<ll> A(N), G;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }

    for (int x = 1; x * x <= S; x++) {
        if (S % x == 0) {
            G.push_back(x);
            if (S/x != x) 
                G.push_back(S/x);
        }
    }
    sort(G.begin(), G.end(), greater<ll>());

    for (auto x: G) {
        ll s_r = 0, cnt = 0; vector<ll> r(N);
        for (int i = 0; i < N; i++) {
            r[i] = A[i] % x;
            s_r += r[i];
        }

        sort(r.begin(), r.end());
        ll l = s_r / x;
        for (int i = N-l; i < N; i++)
            cnt += x - r[i];
        
        if (cnt <= K) {
            cout << x << endl;
            return 0;
        }
    }
}