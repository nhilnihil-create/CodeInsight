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

bool compare(PII a, PII b)
{
    if(a.FF == b.FF) return a.SS < b.SS;
    else return a.FF < b.FF;
}

int main()
{
    //ofstream out("output.txt");
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int h,w,n;
    cin>>h>>w>>n;
    int r[h+1] = {0}, c[w+1] = {0};

    PII p[n];
    loop(i,0,n)
    {
        cin>>p[i].FF>>p[i].SS;
        ++r[p[i].FF]; ++c[p[i].SS];
    }
    sort(p,p+n,compare);

    set<int> st;
    int mx = 0;
    loop(i,1,w+1) mx = max(mx,c[i]);

    loop(i,1,w+1)
    {
        if(c[i] == mx) st.insert(st.end(),i);
    }

    int l = st.size(),it = 0, cnt, ans = 0;
    loop(i,1,h+1)
    {
        cnt = 0;
        while(it < n && p[it].FF == i)
        {
            if(st.find(p[it].SS) != st.end()) ++cnt;
            ++it;
        }

        if(cnt == l) ans = max(ans,r[i] + mx - 1);
        else ans = max(ans,r[i] + mx);
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
