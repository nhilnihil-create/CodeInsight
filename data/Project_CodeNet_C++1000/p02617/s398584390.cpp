#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
#define db double
#define pi 3.14159265358979323846
#define pow pw
int pw(int a,int b){
    int ans=1;
    while(b){
    if (b%2) ans*=a;
    a*=a;
    b/=2;
    }
    return(ans);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,ans=0;
    cin>>n;
    for (int i=0;i<n-1;i++) 
    {
        int a,b;
        cin>>a>>b;
        if (a>b) swap(a,b);
        ans-=a*(n-b+1);
    }
    for (int i=0;i<n;i++)
    {
        ans+=(n-i)*(i+1);
    }
    cout<<ans;
    return 0;
}