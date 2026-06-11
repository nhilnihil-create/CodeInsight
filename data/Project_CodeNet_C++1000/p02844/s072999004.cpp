//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i <= 9; ++i)
    for(int j = 0; j <= 9; ++j)
    for(int k = 0; k <= 9; ++k) {
        bool flag1 = false, flag2 = false, flag3 = false;
        for(int z = 0; z < n; ++z) {
            int tmp = s[z] - '0';
            if(!flag1) {
                if(tmp == i) flag1 = true;
            }
            else if(flag1 && !flag2) {
                if(tmp == j) flag2 = true;
            }
            else if(flag1 && flag2) {
                if(tmp == k) {
                    flag3 = true;
                    break;
                }
            }
        }
        if(flag3) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
