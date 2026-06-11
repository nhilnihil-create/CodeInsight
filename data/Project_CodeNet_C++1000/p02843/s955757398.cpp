#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
    int x; cin >> x;

    bool f = false;
    for(int i = 1; i <= 1000; i++) {
        if(x >= 100*i && x <= 105*i) {
            f = true;
            break;
        }
    }

    if(f) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

}

int main()
{
    solve1();
}