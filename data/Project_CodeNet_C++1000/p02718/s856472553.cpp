#include <bits/stdc++.h>
using namespace std;
int main(){
        int n, m; cin >> n >> m;

        vector<int> v;
        int s = 0;
        for (int x = 0; x < n; ++x){
            int q; cin >> q;
            v.push_back(q);
            s += q;
        }

        int cnt = 0;
        for (auto x : v){
            if (x * 4 * m >= s) cnt++;
        }

        if (cnt >= m) cout << "Yes" << endl;
        else cout << "No" << endl;
    return 0;
}

