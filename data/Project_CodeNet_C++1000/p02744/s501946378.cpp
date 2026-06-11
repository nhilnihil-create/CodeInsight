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

string s;

void find(int n, int st, int gr = 0) {
    if (n == 0) {
        cout << s << "\n";
        return;
    } else {
        for (int i = 1; i <= st; i++) {
            if (i > gr + 1) {
                continue;
            }
            
            s.push_back('a' + i - 1);
            find(n - 1, st, max(gr, i));
            s.pop_back();
        }
    }
}

int main()
{
    fastInp;

    ll n;
    cin >> n;

    find(n, n + 4);
    return 0;
}