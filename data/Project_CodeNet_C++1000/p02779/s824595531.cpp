#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, A;
    cin >> N;
    map<int, int> mp;
    rep(i,N) {
        cin >> A;
        ++mp[A];
    }
    string ans = "YES";
    if (mp.size() != N) ans = "NO";
    cout << ans << endl;
}
