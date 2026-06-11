#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define ppb pop_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int N = 1e5 + 667;
vi v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    v.pb(1);
    v.pb(1);
    v.pb(1);
    v.pb(2);
    v.pb(1);
    v.pb(2);
    v.pb(1);
    v.pb(5);
    v.pb(2);
    v.pb(2);
    v.pb(1);
    v.pb(5);
    v.pb(1);
    v.pb(2);
    v.pb(1);
    v.pb(14);
    v.pb(1);
    v.pb(5);
    v.pb(1);
    v.pb(5);
    v.pb(2);
    v.pb(2);
    v.pb(1);
    v.pb(15);
    v.pb(2);
    v.pb(2);
    v.pb(5);
    v.pb(4);
    v.pb(1);
    v.pb(4);
    v.pb(1);
    v.pb(51);
    
    int k;
    cin >> k;
    cout << v[k-1];
    return 0;
}