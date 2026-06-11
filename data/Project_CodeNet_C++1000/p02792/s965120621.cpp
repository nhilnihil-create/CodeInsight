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
ll gcd(ll a,ll b)
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
int a[11][11];
int main()
{
    int t=1;
   // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int l=i%10;
            int temp=i;
            while(temp>=10)
            temp=temp/10;
            int f=temp;
            a[f][l]++;
        }
        int ans=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            ans=ans+a[i][j]*a[j][i];
        }
        cout<<ans<<endl;
    }
}

