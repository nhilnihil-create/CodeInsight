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
    int max1 = 0, max2 = 0;
    rep(i,N) {
        if (A.at(i) > max2) max2 = A.at(i);
        if (max1 < max2) swap(max1, max2);
    }
    rep(i,N) {
        if (A.at(i) == max1) cout << max2 << endl;
        else cout << max1 << endl;
    }
}
