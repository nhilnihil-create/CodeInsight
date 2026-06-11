//_nebula_
#include<bits/stdc++.h>
using namespace std;
#define int long  long
#define double long double
int t,x;
int max(int a,int b,int c)
{
    return max(a,max(b,c));
}
int min(int a,int b,int c)
{
    return min(a,min(b,c));
}
int fspow(int x,int y)
{
    int ans;
    if(y==0) return 1;
    ans=fspow(x, y/2);
    if(y%2==0) return ans*ans;
    return x*ans*ans;
}
int gcd(int x,int y)
{
    if(x<y) swap(x,y);
    if(y==0) return x;
    return gcd(x%y,y);
}
int p2(int x)
{
    int ans=0;
    while(x>=1)
    {
        ans++;
        x/=2;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    t=1;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
  //  cin>>t;
    // int tmp=t;
    while(t--)
    {
        cin>>x;
        cout<<360/gcd(360, x)<<endl;
    }
    
}
