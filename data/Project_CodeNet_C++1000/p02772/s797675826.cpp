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
#include <queue>
#include <stack>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl

typedef long long ll;

void solve1()
{
    int n;cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    bool f = true;
    rep(i, n) {
        if(a[i]%2 == 0) {
            if(!(a[i]%3 == 0 || a[i]%5 == 0)) {
                f = false;
            }
        }
    }    

    string ans = f?"APPROVED":"DENIED";

    cout << ans << endl;
}

int main()
{
    solve1();
}