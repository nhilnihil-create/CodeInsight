#pragma GCC optimize(3 , "Ofast" , "inline")

#include <bits/stdc++.h>

#define rep(i , a , b) for(register int i=(a);i<=(b);i++)
#define per(i , a , b) for(register int i=(a);i>=(b);i--)


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> pi;

template<class T>
inline void read (T &x) {
    x = 0;
    int sign = 1;
    char c = getchar ();
    while (c < '0' || c > '9') {
        if ( c == '-' ) sign = - 1;
        c = getchar ();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar ();
    }
    x = x * sign;
}

const int maxn = 1e6 + 10;
const int inf = int (1e9);
const ll INF = ll (1e18);
const double PI = acos (- 1);
const int mod = 1e9+7;
const double eps = 1e-8;


string s;
ll dp[maxn][2];
int main () {
    cin>>s;
    reverse (s.begin (),s.end ());
    string t = "0"+s;
    dp[1][0]=t[1]-'0';
    dp[1][1]=10-(t[1]-'0');
    int l = s.size ();
    rep (i,2,l) {
        int x = t[i]-'0';
        dp[i][0]=min (dp[i-1][0]+x,dp[i-1][1]+x+1);
        dp[i][1]=min (dp[i-1][0]+10-x,dp[i-1][1]+9-x);
    }
    printf ("%lld\n",min (dp[l][0],dp[l][1]+1));
    return 0;
}
