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
int a,b,c,d;
cin>>a>>b>>c>>d;
int ans=max(a*c,max(a*d,max(b*c,b*d)));
cout<<ans<<endl;
    return 0;
}
