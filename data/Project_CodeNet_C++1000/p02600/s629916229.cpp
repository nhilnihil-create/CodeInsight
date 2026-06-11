#include <bits/stdc++.h>
using namespace std;
 
#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int main() {sws;

    int x;
    cin >> x;

    vi kyu = {599, 799, 999, 1199, 1399, 1599, 1799, 1999};

    auto it = lower_bound(all(kyu), x);

    cout << 8 - (it - kyu.begin()) << endl;

    return 0;
}