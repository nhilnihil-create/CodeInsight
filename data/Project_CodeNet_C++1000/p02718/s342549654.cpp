#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    int sum = 0;
    bool ok = true;
    string ans;

    sort(A.begin(), A.end(), greater<int>());
    rep(i,N) sum += A.at(i);
    rep(i,M) {
        if (A.at(i) < sum / 4.0 / M) {
            ok = false;
            break;
        }
    }
    if (ok == true) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}