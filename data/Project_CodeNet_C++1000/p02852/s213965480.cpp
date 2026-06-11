#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    string S;
    cin >> N >> M >> S;
    vector<int>ans;
    int res = S.size()-2;
    int i = S.size()-1;
    while (true) {
        int now = -1;
        for(int j = max(0LL,i-M); j <= res; j++) {
            if(S[j] == '0') {
                now = j;
                break;
            }
        }
        if(now == -1) {
            cout << -1 << endl;
            return 0;
        }
        res = max(0LL,i-M-1);
        ans.push_back(i-now);
        i = now;
        if(now == 0) {
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ((i+1 == ans.size())?"\n":" ");
    }
}
