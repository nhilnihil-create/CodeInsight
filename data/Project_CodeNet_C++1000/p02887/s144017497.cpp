#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    int n; string s;
    cin >> n >> s;
    char pre = '#';
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] != pre) {
            pre = s[i];
            ans++;
        }
    }    
    cout << ans;
}


int main() {
    //freopen("input", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}