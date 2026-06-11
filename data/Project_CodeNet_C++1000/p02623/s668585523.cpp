//tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int a[200005],b[200005],n,m,k;
    ll sum=0,ans=0,i,j;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    j=n-1;
    for(i=0;i<m;i++)
    cin>>b[i];
    for(i=0;i<=m;i++)
    {
        while(j>=0&&sum>k)
        {
            sum-=a[j];
            --j;
        }
        if(sum>k)
        break;
        ans=max(ans,i+j+1);
        sum+=b[i];
    }
    cout<<ans<<endl;
    return 0;
}
