#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
int int_max = 2147483647;
int max_n = 1e5;
using mat2d_t = std::vector<std::vector<int64_t>>;


int main(int argc, char **argv) {
    i64 k, q;
    cin >> k >> q;

    std::vector<i64> ds(k);

    for (int i=0; i<k; ++i) {
        cin >> ds[i];
    }

    for (int i=0; i<q; ++i) {
        i64 n, x, m;
        cin >> n >> x >> m;

        i64 ans=n-1;

        std::vector<i64> mod_ds = ds;
        i64 sum_ds{0}, num_zero{0}, an;
        for (i64& d : mod_ds) {
            d = d%m;
            sum_ds += d;
            if (d == 0) {
                ++num_zero;
            }
        }
        //cout << "  "<< sum_ds << endl;
        an = sum_ds * ((n-1)/k);
        num_zero = num_zero * ((n-1)/k);
        i64 n2 = (n-1)%k;
        for (int j=0; j<n2; ++j) {
            an += mod_ds[j];
            if (mod_ds[j] == 0) ++num_zero;
        }
        //cout << "  "<< (an+x)/m << " " << x/m<<endl;
        ans -= ((an+x)/m-x/m);
        ans -= num_zero;

        cout << ans << endl;
    }

    return 0;
}