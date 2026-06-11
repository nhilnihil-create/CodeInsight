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
int val,n;
cin>>val>>n;
int ans=0;
while(n--)
{int x;
cin>>x;
    ans+=x;
}
if(ans>val)
{
    cout<<-1<<endl;
}
else
{
    cout<<val-ans<<endl;
}
    return 0;
}
