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
int x=100000;
int a,b;
cin>>a>>b;
int ans=max(4-a,0*1ll)*x+max(4-b,0*1ll)*x+((a==1&&b==1)?4*x:0);
cout<<ans<<endl;
    return 0;
}
