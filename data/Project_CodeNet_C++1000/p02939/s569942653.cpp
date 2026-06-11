#pragma region noncode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#pragma endregion

int main() {
    string s;
    cin >> s;
    string prevs = s.substr(0, 1);

    ll f = 1;
    ll cnt = 1;
    for(size_t i = 1; i < s.size(); i++) {
        string nxts = s.substr(f, i - f + 1);
        // cout << "nxts=" << nxts << endl;
        if(nxts == prevs || i - f + 1 == 0)
            continue;
        else {
            cnt++;
            // cout << nxts << endl;
        }
        prevs = nxts;
        f = i + 1;
    }
    cout << cnt << endl;
}
