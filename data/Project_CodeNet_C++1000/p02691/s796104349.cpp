#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    unordered_map<int, int> M;
    M.reserve(2 * N);
    rep(i,N) {
        cin >> A[i];
    }
    ll sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        sum += M[i + 1 + A[i]];
        M[(i + 1) - A[i]]++;
    }
    cout << sum << endl;
    
    return 0;
}
