#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int MOD = 1e9 + 7;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)

int a[510000];

int main() {
    string s;
    cin >> s;
    int sz = s.size() + 1;
    for(int i = 0; i < sz;i++){
        if (s[i] == '<') a[i+1] = max(a[i+1], a[i]+1);
    }
    for(int i = sz - 1; i > 0;i--){
        if (s[i-1] == '>') a[i-1] = max(a[i-1], a[i]+1);
    }
    ll ans = 0;
    rep(i,sz) ans += a[i];
    cout << ans << endl;

}