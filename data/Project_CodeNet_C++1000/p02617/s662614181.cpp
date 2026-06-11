#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 100005
#define ll long long

void DBG(){
    cerr << "]\n";
}
template <class H, class... T> void DBG(H h, T... t) {
    cerr << h;
    if (sizeof...(t)) {
        cerr << ", ";
    }
    DBG(t...);
}
#define _DEBUG
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else 
#define dbg(...) 0
#endif

ll n,ans;

int main() {
    cin >> n;
    ans = n;
    for (int i = 1; i < n; i++) {
        ans += (i + 1) * (n - i);
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        ans -= a * (n - b + 1);
    }
    cout << ans << endl;
}