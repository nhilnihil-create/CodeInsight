#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        double w,v,a,b,ti;
        cin>>a>>v;
        cin>>b>>w;
        cin>>ti;
        if((v-w)*ti>=abs(a-b))
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}