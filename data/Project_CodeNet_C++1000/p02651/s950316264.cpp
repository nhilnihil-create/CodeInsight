#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
//#define int __int128
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 100005;

string S;
int n;
int a[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> S;
    S = "#" + S;
    vector < int > V;
    V.pb (0);
    for (int i = n; i >= 1; i--){
        for (int x : V)
            if ((a[i] ^ x) < a[i])
                a[i] ^= x;
        if (S[i] == '1'){
            if (a[i]){
                cout << 1 << endl;
                return;
            }
            continue;
        }
        if (a[i])
            V.pb (a[i]);
        sort (V.begin(), V.end());
        reverse (V.begin(), V.end());
    }
    cout << 0 << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}
