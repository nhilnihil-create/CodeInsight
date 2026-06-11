#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
#define PIL pair<int,LL>
#define PLI pair<LL,int>
#define PIII pair<int,PII>
#define PLL pair<LL,LL>
#define PLII pair<LL,PII>
#define VI vector<int>
#define VL vector<LL>
#define VPII vector<PII>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define EPS 0.00000000001
#define PI acos(-1)
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
using namespace std;

const int MOD = 1e9 + 7;
const LL MX = 60;
const LL INF = 1e9;

int main()
{
    //ofstream out("output.txt");
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    /*
    int t,n;
    cin>>t;
    loop(t1,1,t+1)
    {
        int a[n];
        loop(i,0,n) cin>>a[i];
    }
    */

    int n;
    cin>>n;
    LL a[n+1], sm[n+1];
    loop(i,0,n+1)
    {
        cin>>a[i];
        sm[i] = a[i];
        if(i) sm[i] += sm[i-1];
    }

    LL ans = 1, pre = 1, sl;
    if(n == 0)
    {
        if(a[0] > 1) ans = -1;
    }
    else if(a[0]) ans = -1;
    else
    {
        loop(i,1,n)
        {
            sl = sm[n] - sm[i-1];
            if(pre*2 < a[i]) {ans = -1;break;}
            pre = min(pre*2,sl);
            ans += pre;
            pre -= a[i];
        }

        if(ans != -1)
        {
            if((2*pre) < a[n]) ans = -1;
            else ans += a[n];
        }
    }

    cout<<ans<<'\n';

    /*
    if(f) cout<<"Yes\n";
    else cout<<"No\n";
    */

    return 0;
}
