#include <bits/stdc++.h>
using namespace std;

//g++ -g -o yourexe yourfile.cpp
//./yourexe < yourinput.in > youroutput.out

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define M 1000000007

#define ll long long
#define ld long double
#define vi vector<ll>
#define pi pair<ll, ll>
#define vii vector<pi>
#define vvi vector<vi>
#define pb push_back
#define endl "\n"

#define REP(i, s, e) for (ll i = s; i < e; i++)
#define RREP(i, s, e) for (ll i = s; i > e; i--)

#define all(v) v.begin(), v.end()
#define part(v, s, e) v.begin() + s, v.begin() + e
#define print(v) for (auto i: v) cout << i << " ";

int main() {
    fast;
    ll n;
    cin >> n;
    vii arr(n);
    REP(i, 0, n) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    vvi dp(n, vi(n+1, -1));
    sort(all(arr), greater<pi>());
    dp[0][1] = abs(arr[0].second - 0) * arr[0].first;
    dp[0][0] = abs(arr[0].second - (n-1)) * arr[0].first;
    REP(i, 1, n) {
        REP(j, 0, i+1) {
            dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i].first * abs(arr[i].second - (n-1-(i-j))));
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + arr[i].first * abs(arr[i].second - j));
        }
    }
    cout << *max_element(all(dp[n-1])) << endl;
}
