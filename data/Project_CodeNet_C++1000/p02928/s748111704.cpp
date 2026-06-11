#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;
#define MOD 1000000007

int main(void) {
    ll N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> A2(2*N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A2[i+N] = A[i];
        A2[i] = A[i];
    }

    ll inv_s = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if(A[i] > A[j]) inv_s++;
        }
    }

    ll inv_d = 0;

    for (int i = 0; i < 2*N; i++)
    {
        for (int j = i+1; j < 2*N; j++)
        {
            if(A2[i] > A2[j]) inv_d++;
        }
    }
    
    inv_d -= 2*inv_s;

    ll combi = (K*(K-1))/2;
    combi %= MOD;

    ll ans = (K * inv_s)%MOD + (inv_d * combi)%MOD;

    ans %= MOD;

    cout << ans << endl;
    return 0;
}
