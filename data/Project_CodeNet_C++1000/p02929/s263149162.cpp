#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define N 300005
#define bit(x,y) (x>>y)&1
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
int n;
string s;
long long res = 1;
void solve()
{
    int kt = 1;
    long long Count = 0;
    FOR(i,1,2 * n)
    {
        if(s[i] == 'B') /// odd
        {
            if(Count % 2)
            {
                res *= Count;
                res %= MOD;
                Count --;
            }
            else Count ++;
        }
        else /// even
        {
            if(Count % 2 == 0)
            {
                res *= Count;
                res %= MOD;
                Count --;
            }
            else Count ++;
        }
        if(Count < 0) kt = 0;
    }
    FOR(i,1,n)
    {
        res *= i;
        res %= MOD;
    }
    if(Count == 0 && kt == 1) cout << res;
    else cout << 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("A.inp","r",stdin);
    //freopen("A.out","w",stdout);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    solve();
    return 0;
}
///https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_c
