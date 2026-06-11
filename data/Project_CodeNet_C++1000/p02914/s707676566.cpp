#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll allxor = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        allxor ^= A[i];
    }
    vector<int> odddigit;
    ll ans = 0;
    for (int i = 0; i < 62; i++) {
        if ((allxor>>i)&1) odddigit.push_back(i);
    }
    
    for (int d : odddigit) {
        ans += (1LL<<d);
        ll bitmask = ~(1LL<<d);
        for (int i = 0; i < N; i++) A[i] &= bitmask;
    }
    
    int t = 0;
    for (int i = 61; i >= 0; i--) {
        bool check = false;
        for (int j = t; j < N; j++) {
            if ((A[j]>>i)&1) {
                check = true;
                swap(A[j], A[t]);
            }
        }
        if (!check) continue;
        for (int j = t+1; j < N; j++) {
            if ((A[j]>>i)&1) A[j] ^= A[t];
        }
        t++;
    }
    
    ll evenans = 0;
    for (int i = 0; i < N; i++) {
        if (evenans < (evenans^A[i])) evenans ^= A[i];
    }
    cout << ans + (evenans<<1) << endl;
    return 0;
}
