#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int N; cin >> N;
    ll S=1;
    ll e=1000000000000000000;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    bool zero = find(A.begin(),A.end(),0) != A.end();
    if(zero) {
        cout << "0" << endl;
        return 0;
    }
    else {
        rep(i,N) {
            if (S<=e/A[i]) S *= A[i];
            else {
                cout << "-1" << endl;
                return 0;
            }
        }
        cout << S << endl;
    }
    return 0;
}