#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    vector<ll> A(N, 0);
    rep(i,N) {
        ll tmp; cin >> tmp;
        A[i] = tmp;
    }

    ll money = 1000;
    ll kabu = 0;
    for (int i = 0; i < N-1; ++i) {
    
        if (A[i] < A[i+1]) {
            kabu = money / A[i];
            money = money % A[i];
            money += (kabu * A[i+1]);
        }

    }
    cout << money << endl;

    




}
