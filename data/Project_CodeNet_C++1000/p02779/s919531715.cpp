#include <bits/stdc++.h>
using namespace std;
using ll = long long; //10^19 < 9223372036854775807
#define REP(i,n) for(ll i=0;i<ll(n);i++)

int main(void)
{
    ll N;
    cin >> N;

    ll X;
    set<ll> A;
    REP (i, N) {
        cin >> X;
        A.insert(X);
    }

    if (A.size() == N) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
