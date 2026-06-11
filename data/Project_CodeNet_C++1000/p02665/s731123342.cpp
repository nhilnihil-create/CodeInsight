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
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10, M = 1e9 * 1e8;



int main()
{
    fastInp;

    ll n;
    cin >> n;
    n++;
    vector<ll> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i];
    
    ll ans = 0, pw = 1;

    vector<ll> lft;
    for (int i = 0; i < n; i++) {
        lft.push_back(pw);
        if (vec[i] > pw) {
            cout << "-1";
            return 0;
        }
        ll vl = 0;
        ans += vec[i];
        pw -= vec[i];
        
        if (pw <= M) {
            pw *= 2;
        }
    }

    ll curMax = 0;
    for (int i = n - 1; i > 0; i--) {
        curMax = curMax + vec[i];

        if (lft[i] / 2 <= curMax) {
            ans += lft[i] / 2;
        } else {
            ans += curMax;
        }
    }

    cout << ans;
    return 0;
}