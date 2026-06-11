#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;

vector<pair<ll, ll>> ans;
set<ll> pws;

int main()
{
    fastInp;

    ll n;
    cin >> n;

    for (ll i = 30; i >= 0; i--) {
        pws.insert((1ll << i));
        if ((1ll << i) == n) {
            cout << "No";
            return 0;
        }
    }

    ans.push_back({1, 2});
    ans.push_back({2, 3});
    ans.push_back({3, 1 + n});
    ans.push_back({1 + n, 2 + n});
    ans.push_back({2 + n, 3 + n});

    for (ll i = 4; i <= n; i++) {
        if ((i & (3ll)) == 0) {
            if (i == n) {
                for (ll j = 30; j >= 0; j--) {
                    if ((i & (1ll << j))) {
                        ll snd = (i ^ (1ll << j));
                        ans.push_back({(1ll << j), i});
                        ans.push_back({i + n, (snd + 1)});
                        j = -1;
                    }
                }
                
            } else {
                ans.push_back({i, 1 + n});
                ans.push_back({i + 1, 1 + n});
                ans.push_back({i + n, i + 1});
                ans.push_back({i, i + n + 1});
                i++;
            }
            continue;
        }
        ll cnct = (i - (i & 3ll));
        if ((i & 3ll) == 2ll) {
            ans.push_back({i, cnct});
            ans.push_back({i + n, 3});
        } else {
            ans.push_back({i, cnct});
            ans.push_back({i + n, 2 + n});
        }
    }

    cout << "Yes\n";
    for (auto cur : ans) {
        cout << cur.first << " " << cur.second;
        cout << "\n";
    }

    return 0;
}