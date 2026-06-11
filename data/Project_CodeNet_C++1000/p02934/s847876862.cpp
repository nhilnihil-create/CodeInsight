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

//START OF CODE ->->->->->->->

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);

    rep(i,0,a.size())
    {
        cin>>a[i];
    }

    // long double ans = 0;
    long double v = 0;

    rep(i,0,a.size())
    {
        v += (1/(float)a[i]);
    }

    cout<<setprecision(20)<<1/(float)v<<endl;
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

