#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N-1) {
        int A;
        cin >> A;
        v[A - 1]++;
    }
    rep(i, N) {
        cout << v[i] << endl;
    }
    return 0;
}
