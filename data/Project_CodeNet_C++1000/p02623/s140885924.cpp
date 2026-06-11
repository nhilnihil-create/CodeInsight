#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n,m,k,sm=0,a,ans=0;
    cin>>n>>m>>k;
    vector<lint> V;
    vector<lint>::iterator it;
    for(lint i=1;i<=n;i++){
        cin>>a;
        sm+=a;
        V.pb(sm);
    }
    V.pb(inf);
    sm=0;
    it=upper_bound(V.begin(),V.end(),k-sm);
    ans=max(ans,(lint)(it-V.begin()));
    for(lint i=1;i<=m;i++){
        cin>>a;
        sm+=a;
        if(sm>k) break;
        it=upper_bound(V.begin(),V.end(),k-sm);
        ans=max(ans,i+(lint)(it-V.begin()));
    }
    cout<<ans;
    return 0;
}
