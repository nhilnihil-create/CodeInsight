#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define ld long double
#define oo 2e18
#define OS tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    if (s == "ABC") cout << "ARC\n";
    else cout << "ABC\n";
    return 0;
}