#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define endl '\n'

void solvetask(){
    int n; cin >> n;
    cout << n + n*n + n*n*n << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;// cin >> t;
    while(t--) solvetask();
}