/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAXM = 200010;
// code
#define int long long
/*
0 0 0 0 0 0 0 0 0 0 1 0 0 0
 0 0 0 0 0 0 0 0 0 1 1 0 0
  0 0 0 0 0 0 0 0 1 0 1 0
   0 0 0 0 0 0 0 1 0 0 1
    0 0 0 0 0 0 1 1 0 1
     0 0 0 0 0 1 0 1 1
      0 0 0 0 1 1 1 0
       0 0 0 1 0 0 1
        0 0 1 1 0 1
         0 1 0 1 1
          1 1 1 0
           0 0 1
            0 1
             1
*/
int n; string s;

int lucas(int n, int k) {
    /*
  	for (int i = 30; i >= 0; i--) {
        int nn = (n >> i) & 1;
        int kk = (k >> i) & 1;
        if (nn == 0 && kk == 1) return 0;
    }
    return 1;
  	*/
  	for (int i=0; i<=30; ++i) {
        int nn = (int)((n & (1<<i)) != 0);
        int kk = (int)((k & (1<<i)) != 0);
        if (nn == 0 && kk == 1) return 0;
    }
    return 1;
}

bool check(vector<int> v) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i] * lucas(n-1, i);
        s %= 2;
    }
    return s % 2 == 1;
}

void Solve(){
    cin >> n >> s;
    vector<int> a(n);

    bool f = false;
    for (int i = 0; i < n; i++){
        a[i] = s[i] - '1';
        if (a[i] == 1) f = true;
    }

    if (check(a)){
        cout << 1;
    }else if (f){
        cout << 0;
    }else{
        for (auto &v:a) v /= 2;
        if (check(a)){
            cout << 2;
        }else{
            cout << 0;
        }
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO;
    int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/
