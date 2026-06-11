#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    vector<int> buka(N + 1, 0);

    rep(i,N) ++buka.at(A.at(i));
    for(int i = 1; i <= N; ++i) {
        cout << buka.at(i) << endl;
    }
}