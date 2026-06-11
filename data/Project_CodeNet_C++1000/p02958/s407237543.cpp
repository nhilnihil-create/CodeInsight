#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))

int main() {
    string ans = "YES";
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, N) cin >> p[i];
    int count = 0;
    rep(i, N) {
        if(p[i] != i + 1)
            count++;
    }
    if(count > 2)
        ans = "NO";

    cout << ans << endl;
}