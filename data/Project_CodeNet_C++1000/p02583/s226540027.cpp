#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define sz(a) (int)((a).size())
#define NoType ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair

typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//find_by_order(x) -> returns an iterator to the element at a given position
//order_of_key(x) -> returns the position of a given element

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;

const int mod = (int)1e9 + 7;
const int MAXN = 1e5+12;
//indexed_set s;

int n;
ll l[1005];
map< pair< pair<int,int>, int >, int >m;

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (l[i] != l[j] && l[j] != l[k] && l[i] != l[k]) {
                    if (l[i] + l[j] > l[k] && l[j] + l[k] > l[i] && l[i] + l[k] > l[j]) {
                        vector<int>vec;
                        vec.pb(i),vec.pb(j),vec.pb(k);
                        sort(vec.begin(), vec.end());
                        if (!m[mp(mp(vec[0],vec[1]),vec[2])]) ans++, m[mp(mp(vec[0],vec[1]),vec[2])]=1;

                    }
                }
            }
        }
    }

    cout << ans;

return 0;
}
