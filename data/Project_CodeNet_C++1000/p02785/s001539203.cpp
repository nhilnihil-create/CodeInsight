#include <bits/stdc++.h>
using namespace std;
int main(){
        int n, k; cin >> n >> k;
        vector<long long int> v;
        for (int x = 0; x < n; ++x){
            long long int q; cin >> q;
            v.push_back(q);
        }
        sort(v.begin(), v.end());
        if (k >= v.size()){
            cout << 0 << endl;
            return 0;
        }
        long long int ans = 0;
        for (int x = 0; x < n-k; ++x){
            ans += v[x];
        }
        cout << ans << endl;
    return 0;
}

