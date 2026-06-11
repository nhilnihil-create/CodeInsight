#include<bits/stdc++.h>
# define PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> leaves(n+1);
    vector<long long> non_leaves(n+1);
    vector<long long> ar(n+1);
    vector<long long> max_non_leaves(n+1);
    max_non_leaves[n] = 0;
    for (auto &x: ar)
        cin >> x;
    long long fans = 0;
    if (ar[0] == 0)
    {
        leaves[0] = 0;
        non_leaves[0] = 1;
    }
    else if (ar[0] == 1)
    {
        leaves[0] = 1;
        non_leaves[0] = 0;
    }
    else
    {
        fans = -1;
    }
    if (fans != -1)
    {
        for (long long i = n-1; i>= 0; i--)
        {
            long long ll = ar[i+1];
            long long nl = max_non_leaves[i+1];
            max_non_leaves[i] = nl + ll;
        }

        for (long long i = 1; i<=n; i++)
        {
            long long req_leaves = ar[i];
            long long max_nodes_on_this_lvl = 2 * non_leaves[i-1];
            if (req_leaves > max_nodes_on_this_lvl)
            {
                fans = -1;
                break;
            }
            long long not_leaf = max_nodes_on_this_lvl - req_leaves;
            // if this is the last level then there are zero non leaves
            if (i == n)
                not_leaf = 0;
            if (not_leaf > max_non_leaves[i])
                not_leaf = max_non_leaves[i];

            non_leaves[i] = not_leaf;
            leaves[i] = req_leaves;
        }
        // now we go from bottom and remove extra non-leaves
        if (fans != -1) {
//            for (long long i = n - 1; i >= 0; i--) {
//                long long req_nodes_on_nxt_lvl = leaves[i + 1] + non_leaves[i + 1];
//                if (non_leaves[i] > req_nodes_on_nxt_lvl)
//                    non_leaves[i] = req_nodes_on_nxt_lvl;
//            }
//            fans = 0;
            for (long long i = 0; i <= n; i++)
                fans += leaves[i] + non_leaves[i];
        }
    }
    // exp: 250012613050149995
    cout << fans;
    return 0;
}