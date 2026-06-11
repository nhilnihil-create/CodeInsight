
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
    
    int N;
    cin >> N;
    vector<pair<string,int>> data(N);
    rep(i, N) {
        cin >> data[i].first >> data[i].second;        
    }
    string X;
    cin >> X;

    int ans = 0;
    bool sleeping = false;
    rep(i, N) {
        if (sleeping) {
            ans += data[i].second;
        } else if (data[i].first == X) {
            sleeping = true;
        }
    }

    cout << ans << endl;

    return 0;
}
