#include <bits/stdc++.h>
#define LL long long
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FOD(i,a,b) for(int i=a; i>=b; i--)
#define pa pair<int,int>
#define fi first
#define se second
#define MOD xxx
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) ((n^(1<<(i-1))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))

using namespace std;
int n,k,ans(0),x,y;
pa A[105][105];
int B[105],X[105];
void dq(int i)
{
    if(i>n)
    {
        int ok = 0,s(0);
        FOR(i,1,n)
        if(X[i]==1)
        {
            FOR(j,1,B[i])
            if(X[A[i][j].fi]!=A[i][j].se) ok = 1;
            s += X[i];
        }
        if(ok==0) ans = max( ans , s);
        return;
    }
    X[i] = 0;
    dq(i+1);
    X[i] = 1;
    dq(i+1);
}
int main()
{
    if(fopen("C.inp","r"))
    {
        freopen("C.inp","r",stdin);
        freopen("C.out","w",stdout);
    }
    cin >> n;
    FOR(j,1,n)
    {
        cin >> B[j];
        FOR(i,1,B[j])
        {
            cin >> A[j][i].fi >> A[j][i].se;
        }
    }
    dq(1);
    cout << ans;
	return 0;
}
