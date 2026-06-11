#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
bool fir[200000];
bool sec[200000];
int32_t main() {
    nitin;
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    --a;--b;--c;--d;
    string s;
    cin>>s;
    if(a>b)
    {
        swap(a,b);
        swap(c,d);
    }
    fir[a]=true;
    sec[b]=true;
    for(int i=1;i<=c;i++)
    {
        if(s[i]=='.')
        {
            fir[i]|=fir[i-1];
            fir[i]|=fir[i-2];
        }
    }for(int i=1;i<=d;i++)
    {
        if(s[i]=='.')
        {
            sec[i]|=sec[i-1];
            sec[i]|=sec[i-2];
        }
    }
    if(c<d)
    {
        if(fir[c] && sec[d])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else{
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='.' && sec[i] && fir[i-1] && fir[i+1])
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
        return 0;
    }
    return 0;
}