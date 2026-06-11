// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e10 + 5;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, k, c;
        string s;
        cin >> n >> k >> c >> s;

        int dl[n + 5] = {}, dr[n + 5] = {}, lt = -INF;
        for(int i = 1; i <= n; i++) {
            if(s[i - 1] == 'o' && lt + c < i) {
                lt = i;
                dl[i] = dl[i - 1] + 1;
            }
            else 
                dl[i] = dl[i - 1];
        }
        lt = -INF;
        for(int i = 1; i <= n; i++) {
            if(s[n - i] == 'o' && lt + c < i) {
                lt = i;
                dr[i] = dr[i - 1] + 1;
            }
            else 
                dr[i] = dr[i - 1];
        }


        // for(int i = 0; i <= n; ++i) 
        //     cout << dl[i] << ' ' << dr[i] << '\n';

        for (int i = 0; i < n; i++) {
            int l = i;
            int r = n - 1 - i;
            if(s[i] == 'o' && dl[l] + dr[r] < k) 
                cout << i + 1 << '\n';
        }


    }
    
    return 0;
}