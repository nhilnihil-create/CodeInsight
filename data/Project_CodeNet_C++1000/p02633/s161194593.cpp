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

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10, eps = 1e-7;



int main()
{
    fastInp;

    ll x;
    cin >> x;

    for (ll i = 1; i <= SIZE; i++) {
        if ((i * 360) % x == 0) {
            cout << (i * 360) / x;
            return 0;
        }
    }
    
    return 0;
}