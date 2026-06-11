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
#define vvii vector<vii>
#define pb push_back
#define f first
#define s second
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
    string s;
    cin >> s;
    ll t = 0;
    REP(i, 0, n)
        if (s[i] == 'R')
            t++;
    ll ans = t, sm = 0;
    REP(i, 0, n) {
        if (s[i] == 'R')
            sm++;
        ans = min(ans, max(t, i+1) - sm);
    }
    cout << ans << endl;
}
