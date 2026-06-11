#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

int main(){
    string s, t; cin >> s >> t;

    int ans = 0;
    rep(i, s.size()) {
        if(s[i] != t[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}