#include<bits/stdc++.h>

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FOD(i,b,a) for(i=a;i>=b;i--)
#define pa pair<long long , long long >
#define fi first
#define se second
#define task "x"


typedef long long ll;
const ll M=1e2+1;
const ll N=1e4+1;
using namespace std;

ll i, j, n, ans = 0, x, y, z;
pa a[M][M];
ll b[M],t[M];

void input()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> b[i];
        FOR(j,1,b[i])
        {
            cin >> a[i][j].fi >> a[i][j].se;
        }
    }
}

void xuat()
{
    ll kt = 0,s = 0;
        FOR(i,1,n)
        if(t[i]==1)
        {
            FOR(j,1,b[i])
            if(t[a[i][j].fi]!=a[i][j].se) kt = 1;
            s += 1;
        }
        if(kt==0) ans = max( ans , s);
}

void Try(int i)
{
   int j;
   FOR(j,0,1)
   {
       t[i] = j;
       if(i>=n) {xuat();}
       else {
        Try(i+1);
       }
   }
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    input();
    Try(1);
    cout << ans;
	return 0;
}
