#include <bits/stdc++.h>
#define LL long long
#define FOR(i,a,b) for(LL i=a; i<=b; i++)
#define FOD(i,a,b) for(LL i=a; i>=b; i--)
#define pa pair<int,int>
#define fi first
#define se second
#define MOD xxx
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) ((n^(1<<(i-1))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))

using namespace std;
const int N = 3e5+5;
const LL MOD = 1e9+7;
LL n;
LL A[N];
LL BITO[105],BITZ[105],ans(0),PT[65];
int main()
{
    cin >> n;
    FOR(i,1,n) cin >> A[i];
    PT[0] = 1;
    FOR(i,1,59) PT[i] = (PT[i-1]*2)%MOD;
    FOR(i,1,n)
    {
        FOR(j,1,60)
        {
            LL u = getbit(A[i],j);
            LL t;
            if(u==0) t = BITO[j];
            else t = BITZ[j];
            ans = (ans + (t * PT[j-1])%MOD )%MOD;
            if(u==1) BITO[j]++;
            else BITZ[j]++;
        }
    }
    cout << ans;
	return 0;
}
