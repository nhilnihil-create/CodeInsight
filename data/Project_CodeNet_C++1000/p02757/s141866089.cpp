#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    LL ans = 0;
    if(p == 2) {
        for(int i = 0; i < n; ++i) if((s[i]-'0') % 2 == 0) ans += i+1;
    } else if(p == 5) {
        for(int i = 0; i < n; ++i) if((s[i]-'0') % 5 == 0) ans += i+1;
    } else {
        map<int, int> mp;
        mp[0]++;
        int now = 0, idx = 1;
        for(int i = n-1; i >= 0; --i) {
            now = (now + (s[i]-'0')*idx) % p;
            ans += mp[now]++;
            idx = idx*10%p;
        }
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}