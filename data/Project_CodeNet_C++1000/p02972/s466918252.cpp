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

vector<int> func( int n )
{
    vector<int> div;
    // div.pb(1);
    for ( int i = 1 ; i <= sqrt(n) ; i++ )
    {
        if ( n % i == 0 )
        {
            div.pb(i);
            if ( i != n/i )
            {
                div.pb(n/i);
            }
        }
    }

    return div;
}

//START OF CODE ->->->->->->->

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n+1);

    rep(i,1,a.size())
    {
        cin>>a[i];
    }

    vector<int> ans(n+1);
    vector<int> ans2(n+1);
    repr(i,n,1)
    {
        vector<int> div = func(i);
        if ( a[i] != (ans[i]%2) )
        {
            rep(j,0,div.size())
            {
                ans[div[j]]++;
            }
            ans2[i] = 1;
        }
        else
        {
            ans2[i] = 0;
        }
        
    }

    vector<int> pos;
    rep(i,1,ans2.size())
    {
        if( ans2[i] == 1 )
        {
            pos.pb(i);
        }
    }
    
    cout<<pos.size()<<endl;
    rep(i,0,pos.size())
    {
        cout<<pos[i]<<" ";
    }
    cout<<endl;
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

