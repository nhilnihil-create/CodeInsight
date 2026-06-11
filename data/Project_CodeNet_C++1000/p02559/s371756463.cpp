#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, q;
    cin >> n >> q;
    fenwick_tree<int> fw(n);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        fw.add(i, a);
    }
    for(int qq=0; qq<q; qq++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t) cout << fw.sum(a, b) << endl;
        else fw.add(a, b);
    }

    return 0;
}