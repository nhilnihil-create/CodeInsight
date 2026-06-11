#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;



void run_case() {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(max(a*c, b*d), max(a*d, b*c));

}


int main() {
    //freopen("input", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(6);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}