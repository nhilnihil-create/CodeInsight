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
#define pq priority_queue
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
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    int s = 0;
    rep(i,0,a.size())
    {
        cin>>a[i];
        s += a[i];
    }

    vector<int> div;

    rep(i,1,sqrt(s)+1)
    {
        if ( s % i == 0 )
        {
            div.pb(i);
            if ( s/i != i )
            {
                div.pb(s/i);
            }
        }
    }

    sort(all(div),greater<int>());

    // rep(i,0,div.size())
    // {
    //     out1(div[i]);
    // }
    int ans = 1;
    rep(i,0,div.size())
    {
        vector<int> temp;
        int d = div[i];
        int sum = 0;
        int found = 0;
        rep(j,0,a.size())
        {
            if ( a[j] % d == 0 )
            {
                continue;
            }
            temp.pb(a[j]%d);
            sum += (a[j]%d);
        }
        // out1(sum);
        sort(all(temp));
        int csum = 0;
        rep(j,0,temp.size())
        {
            csum += (temp[j]);

            if ( csum > k )
            {
                break;
            }

            if ( csum == (d*(temp.size()-j-1) - (sum-csum)) )
            {
                found = 1;
                break;
            }
        }

        if ( found == 1 )
        {
            ans = d;
            break;
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

