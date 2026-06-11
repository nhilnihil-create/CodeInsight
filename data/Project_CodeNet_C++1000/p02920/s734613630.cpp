#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 + 10, MOD = 1e9 + 7;



int main()
{
    fastInp;

    ll n;
    cin >> n;
    vector<ll> vec((1ll << n));
    for (int i = 0; i < vec.size(); i++) cin >> vec[i];

    map<ll, ll> cnt;
    for (auto cur : vec) cnt[-cur]++;

    multiset<ll> s;
    s.insert(n + 1);

    /*for (auto cur : cnt) {
        cout << abs(cur.first) << " " << cur.second << "\n";
    }*/
    for (auto cur : cnt) {
        ll curS = cur.second;
        //cout << s.size() << "\n";
        if (curS > s.size()) {
            cout << "No\n";
            return 0;
        }
        vector<ll> k;
        for (int i = 0; i < curS; i++) {
            ll v = *(s.rbegin());
            k.push_back(v);
            s.erase((--s.end()));
        }
        for (int i = 0; i < curS; i++) {
            ll v = k[i];
            for (int j = v - 1; j >= 1; j--) {
                s.insert(j);
            }
        }
    }

    cout << "Yes\n";
    return 0;
}