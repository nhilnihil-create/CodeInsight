#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000

using namespace std;

signed main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt[3] = {0};
    for (int i = 0; i < n; i++){
        if (s[i] == 'R'){
            cnt[0]++;
        } else if (s[i] == 'G'){
            cnt[1]++;
        } else if (s[i] == 'B'){
            cnt[2]++;
        }
    }
    int ans = cnt[0]*cnt[1]*cnt[2];
    for (int k = 1; k <= n/2; k++){
        for (int i = 0; i < n-2*k; i++){
            if (s[i] != s[i+k] && s[i] != s[i+2*k] && s[i+k] != s[i+2*k]){
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}





















