/* Simplicity and Goodness */

#include <bits/stdc++.h>
using namespace std;
#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", (int)(n))
#define prin(n) printf("%d\n", (int)(n))
#define lpri(n) printf("%lld ", n)
#define lprin(n) printf("%lld\n", n)
#define deb(x) cout << #x << " = " << x << ' ';
#define rep(i, a, b) for(int i=(int)(a); i<(int)(b); i++)
#define tc int tt; scn(tt); while(tt --)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using ll = long long;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 998244353;
const int N = 2e5+2;


int main()
{
    string s;
    cin >> s;

    rep(i, 0, s.size()) {
        if(s[i] != '?')
            cout << s[i];
        else
            cout << 'D';
    }
    
    return 0;
}