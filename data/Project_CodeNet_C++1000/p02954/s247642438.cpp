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
    string s;
    cin>>s;

    int psum[s.length()][2] = {0};
    psum[0][0] = 1;
    psum[0][1] = 0;
    rep(i,1,s.length())
    {
        if ( s[i] == 'R' )
        {
            psum[i][0] = psum[i][0] + 1 + psum[i-1][0];
            psum[i][1] += psum[i-1][1];
        }
        else
        {
            psum[i][1] = psum[i][1] + 1 + psum[i-1][1];
            psum[i][0] += psum[i-1][0];
        }
    }

    // rep(i,0,s.length())
    // {
    //     out2(psum[i][0],psum[i][1]);
    // }
    vector<int> pos;

    rep(i,0,s.length()-1)
    {
        if ( s[i] == 'R' && s[i+1] == 'L' )
        {
            pos.pb(i);
        }
    }

    int v[pos.size()+1][2] = {0};
    int l = -1;
    int r = pos[0];
    v[0][1] = ((r-1>=0)?psum[r-1][1]:0) - ((l>=0)?psum[l][1]:0);
    v[0][0] = ((r-1>=0)?psum[r-1][0]:0)- ((l>=0)?psum[l][0]:0);
    rep(i,1,pos.size())
    {
        l = r+1;
        r = pos[i];
        v[i][0] = ((r-1>=0)?psum[r-1][0]:0) - ((l>=0)?psum[l][0]:0);
        v[i][1] = ((r-1>=0)?psum[r-1][1]:0) - ((l>=0)?psum[l][1]:0);
    }
    l = r+1;
    r = s.length();

    v[pos.size()][1] = ((r-1>=0)?psum[r-1][1]:0) - ((l>=0)?psum[l][1]:0);
    v[pos.size()][0] = ((r-1>=0)?psum[r-1][0]:0) - ((l>=0)?psum[l][0]:0);

    // rep(i,0,pos.size()+1)
    // {
    //     out2(v[i][0],v[i][1]);
    // }

    int sz = pos.size()+1;

    vector<int> ans(s.length(),0);
    vector<int> val;

    rep(i,0,pos.size())
    {
        ans[pos[i]] = 1;
        ans[pos[i]+1] = 1;
    }

    rep(i,0,sz-1)
    {
        int x = v[i][0] + v[i+1][1];
        if ( x % 2 == 0 )
        {
            ans[pos[i]] += x/2;
            ans[pos[i]+1] += x/2;
            val.pb(-1);
        }
        else
        {
            if ( v[i][0] > v[i+1][1] )
            {
                ans[pos[i]] += x/2 + 1;
                ans[pos[i]+1] += x/2;
                val.pb(v[i][0]);
            }
            else
            {
                ans[pos[i]] += x/2;
                ans[pos[i]+1] += x/2 + 1;
                val.pb(v[i+1][1]);
            }
        }
    }
    // rep(i,0,ans.size())
    // {
    //     out1(ans[i]);
    // }
    int z = *max_element(all(val));
    // out1(z);
    // rep(i,0,val.size())
    // {
    //     out1(val[i]);
    // }
    int par = z%2;
    rep(i,0,val.size())
    {
        if ( val[i] == -1 )
        {
            continue;
        }
        else
        {
            int pari = val[i]%2;

            if ( pari != par )
            {
                swap(ans[pos[i]],ans[pos[i]+1]);
            }
        }
    }

    if ( par )
    {
        rep(i,0,pos.size())
        {
            swap(ans[pos[i]],ans[pos[i]+1]);
        }
    }

    rep(i,0,ans.size())
    {
        cout<<ans[i]<<" ";
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

