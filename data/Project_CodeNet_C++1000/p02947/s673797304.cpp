#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;
using namespace std;

int main(void){
    int n;
    cin >> n;
    string s;
    set<string> set;
    unordered_map<string, int> map;
    ll res = 0;
    rep (i, n) {
        cin >> s;
        sort(s.begin(), s.end());
        set.insert(s);
        map[s]++;
    }
    for (auto itr = set.begin(); itr != set.end(); ++itr) {
        ll n = map[*itr];
        res += n*(n-1)/2;
    }
    cout << res << endl;
}