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
const LL MX = 1e6 + 100;
const LL INF = 1e9;

void print_a(VI v)
{
    if(v.size()) cout<<v[0];
    loop(i,1,v.size()) cout<<' '<<v[i];
    cout<<'\n';
}

VVI init_vvi(int n, int m, int val)
{
    return VVI(n,VI(m,val));
}

VVL init_vvl(int n, int m, LL val)
{
    return VVL(n,VL(m,val));
}

int main()
{
    //ofstream out("output.txt");
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    VI v(MX,0);
    cin>>n;
    int a[n];
    loop(i,0,n)
    {
        cin>>a[i];
        ++v[a[i]];
    }

    int ans = 0, f;
    loop(i,0,n)
    {
        f = 1;
        if(v[a[i]] > 1) f = 0;
        else if(a[i] != 1 && v[1]) f = 0;
        else
        {
            int n1 = sqrt(a[i]);
            loop(j,2,n1+1)
            {
                if(a[i] % j == 0)
                {
                    if(v[j]) {f = 0; break;}
                    if(v[a[i]/j]) {f = 0; break;}
                }
            }
        }

        if(f) ++ans;
    }

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
