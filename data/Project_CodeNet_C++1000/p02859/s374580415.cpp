#include <bits/stdc++.h>
using namespace std;

#define int long long
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
const int MOD = 10000;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))
int gcd(int x,int y){if(y==0) return x; return gcd(y, x%y);}
int lcm(int x,int y){return x/gcd(x,y)*y;}

signed main() {
    int r; cin >> r;
    cout << r*r << endl;
}