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
    ll x; cin >> x;
    ll ansa;
    ll ansb;
    for(ll i = -1000; i <= 1000; i++) {
        for(ll j = -1000; j <= 1000; j++) {
            ll a = (ll)pow(i, 5);
            ll b = (ll)pow(j, 5);

            if(a - b == x) {
                ansa = i;
                ansb = j;
                break;
            }
        }
    }

    cout << ansa << " " << ansb << endl;
}

int main()
{
    solve1();
}
