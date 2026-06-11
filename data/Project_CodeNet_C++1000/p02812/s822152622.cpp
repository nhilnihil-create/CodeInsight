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
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    rep(i, n-2) {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ans++;
    }
    cout << ans << endl;

    return 0;
}
