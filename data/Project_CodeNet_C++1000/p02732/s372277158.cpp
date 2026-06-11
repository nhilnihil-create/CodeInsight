#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, ll> mp;

    rep(i, N) {
        cin >> A[i];
        mp[A[i]]++;
    }

    ll res = 0;
    for (auto itr : mp) {
        ll cnt = itr.second;
        res += (cnt * (cnt - 1)) / 2;
    }

    rep(i, N) {
        ll cnt1 = mp[A[i]];
        ll cnt2 = cnt1 - 1;
        cnt1 = (cnt1 * (cnt1 - 1)) / 2;
        cnt2 = (cnt2 * (cnt2 - 1)) / 2;
        cout << res - (cnt1 - cnt2) << endl;
    }
    return 0;
}