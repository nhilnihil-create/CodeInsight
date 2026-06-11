#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> s(n);
    int a;
    rep(i, q) {
        cin >> a;
        a--;
        s[a]++;
    }
    rep(i, n) {
        if (q-s[i]<k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}