/* Author: Rennan Rocha
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>

#define INF 1e18
#define MOD 1000000007

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order(); order_of_key();

int l[200010], r[200010];
int main() {
    ios_base::sync_with_stdio(false);

    int n, k, c;
    string s;
    cin >> n >> k >> c;
    cin >> s;

    int trab=0;
    for(int i = 0; i < n;) {
        if(trab>=k) break;
        if(s[i] == 'o') {
            l[trab] = i;
            trab++;
            i += c+1;
        }else {
            i++;
        }
    }
    trab=k-1;
    for(int i = n-1; i >= 0;) {
        if(trab<0) break;
        if(s[i] == 'o') {
            r[trab] = i;
            trab--;
            i -= c+1;
        }else {
            i--;
        }
    }

    for(int i = 0; i < k; i++) {
        if(l[i] == r[i]) {
            cout << l[i]+1 << "\n";
        }
    }
}
