#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using p = pair<int, int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);

    sort(a.begin(), a.end());
    rep(i,n-1) {
        if (a.at(i) == a.at(i + 1)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}