#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    int n, k; sc(n), sc(k);
    ll ans = 0, cnt = 0, tmp = 0;
    string s, tmps; cin >> s;
    tmps = s[0];
    rep(i, 1, s.size()){
        if (s[i]==tmps[0]) tmp += 1;
        else {
            cnt += 1;
            ans += tmp;
            tmp = 0;
            tmps = s[i];
        }
    }
    ans += tmp;
    rep(i, 0, k){
        if (cnt<=0) break;
        else if (cnt==1) ans += 1;
        else ans += 2;
        cnt -= 2;
    }
    cout << ans << endl;
    return 0;
}