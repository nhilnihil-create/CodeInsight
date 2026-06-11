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

    ll m, d;
    cin >> m >> d;
    ll m1, d1;
    cin >> m1 >> d1;
    
    if (m1 != m) {
        cout << "1";
    } else {
        cout << "0";
    }

    return 0;
}