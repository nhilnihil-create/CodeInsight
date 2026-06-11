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

    ll x;
    cin >> x;
    if (x >= 10000) {
        cout << "1";
    } else {
        ll vl = x / 100, vl2 = x % 100;
        if (vl >= (vl2 - 1) / 5 + 1) {
            cout << "1";
        } else {
            cout << "0";
        }
    }

    return 0;
}