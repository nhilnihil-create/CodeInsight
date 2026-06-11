#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> H(N);
    rep(i, N){
        cin >> H[i];
    }
    int ans = 0;
    int cnt = 0;
    int now = H[0];
    for (int i = 1; i < N; i++){
        int nex = H[i];
        if(now >= nex){
            now = nex;
            cnt++;
            ans = max(ans, cnt);
        } else {
            ans = max(ans, cnt);
            cnt = 0;
            now = nex;
        }
    }

    cout << ans << endl;

    return 0;
}