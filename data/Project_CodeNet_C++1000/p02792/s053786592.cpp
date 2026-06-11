#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

LL cnt[10][10];

int div(int x) {
    while(x/10) x/= 10;
    return x;
}

void run_case() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cnt[i%10][div(i)]++;
    LL ans = 0;
    for(int i = 0; i <= 9; ++i) 
        for(int j = 0; j <= 9; ++j)
            ans += cnt[i][j]*cnt[j][i];
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