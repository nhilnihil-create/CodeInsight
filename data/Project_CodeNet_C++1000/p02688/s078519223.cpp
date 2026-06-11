#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N,K; cin >> N >> K;
    int cnt[N+10] = {};

    for(int i=1; i<=K; i++) { //どの種類のお菓子か
        int d; cin >> d;
        for(int j=1; j<=d; j++) {
            int a; cin >> a; //だれがもってるか
            cnt[a]++;
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++) {
        if(cnt[i]==0) ans++;
    }

    cout << ans << endl;
}