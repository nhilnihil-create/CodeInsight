#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int n,d,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin>>n>>d;
    d=2*d+1;
    if(n%d==0)
        ans=n/d;
    else
        ans=n/d+1;
    cout<<ans;
}
