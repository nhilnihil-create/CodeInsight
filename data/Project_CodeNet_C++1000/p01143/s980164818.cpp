#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    vector<int> ans;
    while(true){
        int N, M, P; cin >> N >> M >> P;
        if(N == 0 && M == 0 && P == 0) break;
        int people = 0, tousen = 0;
        rep(i, N){
            int temp; cin >> temp;
            people += temp;
            if(i+1 == M) tousen = temp;
        }
        int pool = people*(100-P);
        if(tousen > 0) ans.push_back(pool/tousen);
        else ans.push_back(0);
    }
    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}
