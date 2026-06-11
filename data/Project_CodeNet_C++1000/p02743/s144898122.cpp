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

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 * 1e9 + 10;

int main()
{
    fastInp;

    ll a, b, c;
    cin >> a >> b >> c;
    ll d = (c - a - b);
    if (d > 0 && d * d > 4 * a * b) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}