#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,n,t,a,b,c,l,r;
    cin>>n>>m>>k;
    string s[8];
    for(i=0; i<n; i++)
        cin>>s[i];
    ll cnt,ans=0;
    for(i=0; i<(1<<n); i++)
    {
        for(j=0; j<(1<<m); j++)
        {
            cnt=0;
            for(a=0; a<n; a++)
            {
                for(b=0; b<m; b++)
                {
                    if(i & (1<<a) && j &(1<<b) && s[a][b]=='#')
                        cnt++;
                }
            }
            if(cnt==k)
                ans++;
        }
    }
    cout<<ans<<'\n';
}



