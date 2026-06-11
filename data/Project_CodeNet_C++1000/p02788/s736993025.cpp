#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

const int MAXN = (int)1e3 + 5;
const int MAXM = (int)1e4 + 5;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<int, long long>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    set<pair<long long, long long>> st;
    long long neg = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = arr[i].first;
        while (!st.empty() && (*st.begin()).first <= pos) {
            neg -= (*st.begin()).second;
            st.erase(st.begin());
        }
        arr[i].second -= neg;
        if (arr[i].second > 0) {
            ans += (arr[i].second + a - 1) / a;
            long long x = (arr[i].second + a - 1) / a * a;
            neg += x;
            st.insert({pos + 2LL*d + 1, x});
        }
//        cout << i << endl;
    }

    cout << ans << '\n';
    return 0;
}