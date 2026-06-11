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
    int x, n; cin >> x >> n;
    set<int> p;
    rep(i, n) {
        int tmp; cin >> tmp;
        p.insert(tmp);
    }

    int diff = 105;
    int ans = 105;
    for(int i = -1; i <= 101; i++) {
        if(p.find(i) != p.end()) continue;
        if(diff > abs(x-i)) {
            ans = i;
            diff = abs(x-i);
        }
    }
    cout << ans << endl;

    return 0;
}