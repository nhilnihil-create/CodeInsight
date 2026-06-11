

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int s, n, a[100005];
vector<pair<int, int> > v;

int main(void) {
    cin >> n;
    rep(i, 0, n) scanf("%d", &a[i]);
    sort(a, a+n);
    swap(a[1], a[n-1]);

    s = a[0];
 
    rep(i, 1, n) {
        int x, y;
        if (i==n-1 || a[i+1]<0) {
            x = max(s, a[i]);
            y = min(s, a[i]);
        } else {
            x = min(s, a[i]);
            y = max(s, a[i]);
        }
        s = x - y;
        v.pb(mp(x, y));
    }
    

    cout << s << endl;
    for (int i=0; i<(int)v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);

	return 0;
}
