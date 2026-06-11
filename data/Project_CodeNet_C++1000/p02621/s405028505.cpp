#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using _TYPE = int;
typedef tree< _TYPE, null_type, less< _TYPE >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main() {
    IO;
    int a;
    cin >> a;
    cout << a + pow(a, 3) + pow(a, 2);
    return 0;
}