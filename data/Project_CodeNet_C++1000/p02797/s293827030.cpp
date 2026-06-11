//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> ans(n);
    for(int i = 0; i <= n; ++i) {
        if(i < k) {
            ans[i] = s;
        }else{
            if(s != 1e9) {
                ans[i] = s+1;
            }else {
                ans[i] = 1;
            }
        }
    }

    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
