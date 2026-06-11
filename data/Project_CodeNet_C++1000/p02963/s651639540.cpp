
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    LL S;
    cin >> S;
    LL x1 = 0;
    LL y1 = 0;
    LL x2 = 1000000000;
    LL y2 = 1;
    LL x3 = (x2-S%x2)%x2;;
    LL y3 = (S+x3)/x2;

    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl; 

    return 0;
}
