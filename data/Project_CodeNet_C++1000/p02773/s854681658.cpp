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
#define PI 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;


void solve1() {
    int n; cin >> n;
    vector<string> s(n);
    set<string> ss;
    map<string, int> m;
    rep(i,n) {
        cin >> s[i];
        ss.insert(s[i]);
    }

    sort(all(s));
    int maxnum = -1;
    for(auto itr = ss.begin(); itr != ss.end(); itr++) {
        int num = upper_bound(all(s), *itr) - lower_bound(all(s), *itr);
        m.insert(make_pair(*itr, num));
        maxnum = max(num, maxnum);
    }

    for (auto itr = ss.begin(); itr != ss.end(); itr++)
    {
        if(m[*itr] == maxnum) {
            cout << *itr << endl;
        }
    }
}

int main()
{
    solve1();
}
