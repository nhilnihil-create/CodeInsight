#include <bits/stdc++.h>
#include <string>
#define MAX 100007
#define scn1(a) scanf("%d", &a);
#define scn2(a, b) scanf("%d %d", &a, &b);
#define scn3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define lscn1(a) scanf("%lli", &a);
#define lscn2(a, b) scanf("%lli %lli", &a, &b);
#define lscn3(a, b, c) scanf("%lli %lli %lli", &a, &b, &c);
#define prnt(a) printf("%d\n", a);
#define forr(i, a, n) for(int i=a;i<n;i++)
#define nl puts("");
#define enl cout << "\n";
#define CHK(a) cout << (#a) << " = " << (a) << endl;
typedef long long int ll;
using namespace std;
void LOOPCHK(int a[],int n){for(int i=0;i<n;i++)cout<<a[i]<<" ";enl;}

int n, a[21], b[21][21], c[21][21];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt=1;

    // cin >> tt;
    for(int cse=1; cse<=tt; cse++)
    {
        int ans=0;
        cin >> n;
        forr(i, 1, n+1)
        {
            cin >> a[i];
        	forr(j, 1, a[i]+1) cin >> b[i][j] >> c[i][j];
        }
        forr(i, 1, (1<<n))
        {
        	bool flg = 1;
        	forr(j, 1, n+1)
        	{
        		if( !(i & (1<<(j-1)))  ) continue;
        		forr(k, 1, a[j]+1) if(((i >> (b[j][k]-1)) & 1) ^ c[j][k]) flg = false;
        	}
        	if(flg)
        	{
        		int nm = i, cnt = 0;
        		while(nm!=0)
        		{
        			cnt += (nm&1);
        			nm >>= 1;
        		}
        		ans = max(ans, cnt);
        	}
        }
        // cout << "Case " << cse <<  ": ";
        cout << ans << endl;
    }
    return 0;
}
