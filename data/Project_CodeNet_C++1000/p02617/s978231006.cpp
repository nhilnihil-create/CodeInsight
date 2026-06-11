#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
#define PIL pair<int,LL>
#define PLI pair<LL,int>
#define PIII pair<int,PII>
#define PLL pair<LL,LL>
#define PLII pair<LL,PII>
#define VI vector<int>
#define VVI vector<VI>
#define VL vector<LL>
#define VVL vector<VL>
#define VPII vector<PII>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define all(x) x.begin(),x.end()
#define watch(x) cout<<(#x)<<" = "<<(x)<<'\n'
#define mset(a,v) memset(a,v,sizeof(a))
#define setp(x) cout<<fixed<<setprecision(x)
#define EPS 0.00000000001
#define PI acos(-1)
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
using namespace std;

const int MOD = 1e9 + 7;
const LL MX = 1e9;
const LL INF = 1e9;

int main()
{
    //ofstream out("output.txt");
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    LL n, u, v;
    cin>>n;
    VL g[n+1];
    loop(i,1,n)
    {
        cin>>u>>v;
        g[u].PB(v); g[v].PB(u);
    }

    LL cp, cc, sum = 0;
    cp = 0;
    loop(i,1,n+1)
    {
        cc = cp;
        for(int j : g[i])
        {
            if(j < i) ++cc;
        }
        sum += cc;
        cp = cc;
    }

    LL ne = sum, ans = 0, ans1;
    loop(i,1,n+1)
    {
        for(int j : g[i])
        {
            if(j > i) sum -= (n - j + 1);
        }
        ans1 = ((n - i + 1) * (n - i + 2))/2;
        ans += ans1;
        ne += sum;
    }

    ans -= ne;

    cout<<ans<<'\n';

    /*
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        loop(i,0,n)
        {
            cin>>a[i];
        }
    }
    */

    /*
    int n;
    cin>>n;
    int a[n];
    loop(i,0,n)
    {
        cin>>a[i];
    }
    */

    /*
    cout<<ans<<'\n';

    if(f) cout<<"YES\n";
    else cout<<"NO\n";

    if(f) cout<<"Yes\n";
    else cout<<"No\n";
    */

    return 0;
}
