#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#define all(x) x.begin(), x.end()
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

int main(){
    int n, k; cin >> n >> k;
    vector<int> p;
    rep(i, n) {
        int tmp; cin >> tmp;
        p.push_back(tmp);
    }

    sort(all(p));
    int ans = 0;
    rep(i, k) ans += p[i];
    cout << ans << endl;

    return 0;
}