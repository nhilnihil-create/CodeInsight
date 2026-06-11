#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N, M; cin >> N >> M;
    vector<ll> A(3,-1);
    rep(i,M) {
        ll tmp, tmp2; cin >> tmp >> tmp2;
        if (A[tmp-1] != -1 && A[tmp-1] != tmp2) {
            cout << -1 << endl;
            exit(0);
        }
        else{
            A[tmp-1] = tmp2;
        }
    }
    bool ng = false;
    if (N == 1) {
        if (A[0] == -1) A[0] = 0;
    }
    else if (N == 2) {
        if (A[0] == -1) A[0] = 1;
        else if (A[0] == 0) ng = true;
    }
    else {
        if (A[0] == -1) A[0] = 1;
        else if (A[0] == 0) ng = true;
    }
    if (ng) {
        cout << -1;
    }
    else {
        rep(i,N) {
            if (A[i] == -1) A[i] = 0;
            cout << A[i];
        }
    }
    cout << endl;
        



}
