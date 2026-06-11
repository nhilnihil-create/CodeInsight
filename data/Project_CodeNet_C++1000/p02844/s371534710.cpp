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



int main()
{
    fastInp;

    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                ll curPos = 0;
                for (int t = 0; t < s.size(); t++) {
                    if (curPos == 3) continue;

                    if (curPos == 0) {
                        if (s[t] - '0' == i) curPos++;
                    } else if (curPos == 1) {
                        if (s[t] - '0' == j) curPos++;
                    } else {
                        if (s[t] - '0' == k) curPos++;
                    }
                }

                if (curPos == 3) ans++;
            }
        }
    }

    cout << ans;

    return 0;
}