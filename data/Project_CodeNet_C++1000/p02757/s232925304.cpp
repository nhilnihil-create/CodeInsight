#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,P;
    string S;
    cin >> N >> P >> S;
    if(P != 2 && P != 5) {
        int ans = 0;
        vector<int>cnt(P);
        int now = 0;
        int res2 = 1;
        cnt[0] = 1;
        for(int i = N-1; i >= 0; i--) {
            now = (now+(S[i]-'0')*res2)%P;
            cnt[now]++;
            res2 = res2*10%P;
        }
        for(int i = 0; i < P; i++) {
            ans+=cnt[i]*(cnt[i]-1)/2;
        }
        cout << ans << endl;
        return 0;
    }
    int res = 0;
    for(int i = 0; i < N; i++) {
        if((S[N-1-i]-'0')%P == 0) {
            res+=N-i;
        }
    }
    cout << res << endl;
}