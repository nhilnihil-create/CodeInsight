#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int x,n;
    cin >> x >> n;
    int p[110];
    rep(i, 110) p[i] = i;
    rep(i,n){
        int k;
        cin >> k;
        p[k] = 0;
    }
    int cnt = 20000;
    int ans;
    for (int i = 101; i >= 0;i--){
        cnt = min(cnt, abs(x - p[i]));
        if(cnt==abs(x-p[i]))
            ans = i;
    }
    cnt = min(cnt, abs(x + 1));
    if(cnt==abs(x+1))
        ans = -1;
    cout << ans << endl;
}