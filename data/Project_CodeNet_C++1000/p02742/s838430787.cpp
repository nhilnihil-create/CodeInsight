#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;
int ans=n*m;
if(n==1||m==1)
{
    cout<<1<<endl;
    return 0;
}
ans+=1;
ans/=2;
cout<<ans<<endl;
    return 0;
}
