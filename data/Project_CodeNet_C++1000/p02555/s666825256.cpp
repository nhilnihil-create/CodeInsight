#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int mod = 1e9+7;

int main() {
    ll S;
    cin >> S;
    vector<ll> A(S+1, 0);
    A[0] = 1;
    for (int i=1; i<=S; ++i) {
        for (int j=i-3; j>=0; --j) {
            A[i] += A[j];
            A[i] %= mod;
        }
    }
    cout << A[S] << endl;
    return 0;
}