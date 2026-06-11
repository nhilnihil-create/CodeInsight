#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N,0);

    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
        B[A[i] - 1]++;
    }

    ll prod = 0;
    for(ll i = 0; i < N; i++){
        prod += B[i] * (B[i] - 1) / 2;
    }

    for(ll k = 0; k < N; k++){
        ll pat;
        pat = prod - (B[A[k]-1] - 1);
        cout << pat << endl;
    }

    return 0;
}
