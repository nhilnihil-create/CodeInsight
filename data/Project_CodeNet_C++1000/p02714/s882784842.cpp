#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n;
    std::cout.precision(10);
    int yes=0;
    cin>>n;
    string s;
    cin>>s;
    int r=0,g=0,b=0;
    ll dpr[n],dpg[n],dpb[n];
    for(i=0;i<n;i++)
    {
        if(s[i]=='R')
        {
            r++;
        }
        else if(s[i]=='G'){
            g++;
        }
        else
        {
            b++;
        }
        dpr[i]=r;
        dpb[i]=b;
        dpg[i]=g;
    }
    // for(i=0;i<n;i++)
    // {
    //     cout<<dpr[i]<<" ";
    // }
    ll ans=0;
    for(j=1;j<n-1;j++)
    {
        if(s[j]=='R')
        {
            ans+=dpb[j-1]*(dpg[n-1]-dpg[j]);
            ans+=dpg[j-1]*(dpb[n-1]-dpb[j]);
        }
        else if(s[j]=='G')
        {
            ans+=dpr[j-1]*(dpb[n-1]-dpb[j]);
            ans+=dpb[j-1]*(dpr[n-1]-dpr[j]);
        }
        else if(s[j]=='B')
        {
            ans+=dpr[j-1]*(dpg[n-1]-dpg[j]);
            ans+=dpg[j-1]*(dpr[n-1]-dpr[j]);
        }
        int i=j-1,k=j+1;

        while(i>=0 && k<n)
        {
            if(s[i]!=s[j] && s[i]!=s[k] && s[k]!=s[j])
            {
                ans--;
            }
            
            i--;
            k++;
        }
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int i,j,k;
    int t;
    std::cout.precision(10);
    t=1;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}