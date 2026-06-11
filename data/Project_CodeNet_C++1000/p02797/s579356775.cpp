#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> ans(n);

    int prime;
    if(s != 144701) prime = 144701;
    else prime = 144497;

    if(k == 0) {
        rep(i, n) cout << prime << " ";
        cout << endl;
        return 0;
    }

    int kusa;
    if(s == 1 || s == 2) kusa = s+1;
    else kusa = s-1;

    rep(i, n) {
        if(i < k) ans[i] = s;
        else ans[i] = kusa;
    }

    //output
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
