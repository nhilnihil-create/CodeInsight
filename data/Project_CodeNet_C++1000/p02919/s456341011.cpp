#include<bits/stdc++.h>
#define se second
#define fi first
using namespace std;
const int MAXN = 10+1e5;
typedef pair<int,int> I;
typedef long long LL;
const LL oo = 1e9;
int n,m;
int l1[MAXN],r1[MAXN];
LL a[MAXN];

void Inout()
{
    #define TASK "ABC"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

int main()
{
//Inout();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>n;
    for (int i=1; i<=n; ++i) cin >>a[i];

    l1[0] = 0;
    a[n+1] = oo;
    r1[n] = n+1;

    for (int i=1; i<=n; ++i)
        if ( a[i] < a[i-1] ) l1[i] = i-1;
        else {
            int x = l1[i-1];
            while( a[x] <= a[i] && x)
                x = l1[x];
            l1[i] = x;
        }

    for (int i=n-1; i; --i)
        if ( a[i] < a[i+1] ) r1[i] = i+1;
        else {
            int x = r1[i+1];
            while( a[x] <= a[i] && x <= n)
                x = r1[x];
            r1[i] = x;
        }
    //for (int i=1; i<=n; ++i)
     //   cerr <<l1[i] <<' ' <<r1[i] <<'\n';
    LL ans = 0;
    for (int i=1; i<=n; ++i) {
        int d = 0,
            l = l1[i],
            r = r1[i];
        if ( l>0 ) {
            --l;
            while( a[l] < a[i] && l ) l = l1[l];
            d += (r1[i] - i )* (l1[i] - l);
        }
        if ( r<n+1 ) {
            ++r;
            while( a[r] < a[i] && r<=n) r = r1[r];
            d += (r - r1[i] )* (i - l1[i]) ;
        }
        ans += d*a[i];
        //cout <<l <<' ' <<r <<' ' <<d <<'\n';
    }
    cout <<ans;
return 0;
}
