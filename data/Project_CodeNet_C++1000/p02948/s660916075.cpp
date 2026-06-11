#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 1000000007
#define inf 1e18+42
#define endl "\n"
#define pi 3.1415926535897932384626433832795028841971693993751058
#define maxn 100005

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(auto it=A.begin();it!=A.end();it++)

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define zero(x) memset(x,0,sizeof(x));
 
using namespace std;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//START OF CODE ->->->->->->->

void solve()
{
    int n,m;
    cin>>n>>m;

    // map< int,priority_queue<int> > p;
    vector< pair<int,int> > p;

    rep(i,0,n)
    {
        int a,b;
        cin>>a>>b;

        p.pb(mp(a,b));
    }
    int ans = 0;
    sort(all(p));
    priority_queue<int> s;
    int idx = 0;
    rep(i,1,m+1)
    {
        while( idx < n && p[idx].ft <= i )
        {
            s.push(p[idx].sd);
            idx++;
        }

        if ( !s.empty() )
        {
            ans += s.top();
            s.pop();
        }
    }
    cout<<ans<<endl;
}

//END OF CODE ->->->->->->->->

signed main()
{
    fast;
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}

