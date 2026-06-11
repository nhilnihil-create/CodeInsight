#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N);
    vector<pll> ans;
    deque<ll> B, C;
    rep(i, N) {
        cin >> A[i];
        if (A[i] >= 0)
            B.push_back(A[i]);
        else
            C.push_back(A[i]);
    }

    sort(all(B)), sort(all(C), greater<ll>());

    if (B.size() == N) {
        ll n = B.front() - B.back();
        ans.push_back({B.front(), B.back()});
        B.pop_front(), B.pop_back();
        C.push_back(n);
    } else if (C.size() == N) {
        ll n = C.front() - C.back();
        ans.push_back({C.front(), C.back()});
        C.pop_back(), C.pop_front();
        B.push_back(n);
    }

    while (B.size() != 1 && !B.empty()) {
        ll b = B.front();
        ll c = C.front();
        ll n = c - b;
        B.pop_front(), C.pop_front();
        C.push_back(n);
        ans.push_back({c, b});
    }

    while (!C.empty() && !B.empty()) {
        ll b = B.front();
        ll c = C.front();
        ll n = b - c;
        B.pop_front(), C.pop_front();
        B.push_back(n);
        ans.push_back({b, c});
    }

    cout << ans.back().first - ans.back().second << endl;
    rep(i, ans.size()) { cout << ans[i].first << " " << ans[i].second << endl; }
}