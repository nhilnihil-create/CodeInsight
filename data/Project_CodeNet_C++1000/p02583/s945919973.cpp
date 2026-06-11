#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
ll a[104];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,c,d,l,r;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    ll cnt=0;
    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            for(k=j+1; k<=n; k++)
            {
                if(a[i]==a[j] || a[i]==a[k] || a[j]==a[k])
                    continue;
                if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i])
                    cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
}






