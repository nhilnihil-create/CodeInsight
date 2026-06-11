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
    int n, x; cin >> n >> x;
    vector<int> l(n);
    rep(i, n) {
        cin >> l[i];
    }

    int d[2*n];
    d[0] = 0;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        d[i] = d[i-1] + l[i-1];
        if(d[i] <= x) {
            ans ++;
        }
    }

    cout << ans << endl;

 
}

int main()
{
    solve1();
}
