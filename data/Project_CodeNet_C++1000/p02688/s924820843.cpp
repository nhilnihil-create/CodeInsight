#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;


int solve(){
    int n,k;
    cin>>n>>k;
    vector<bool> vis(n+1);
    for(int i=0;i<k;i++){
        int q,t;
        cin>>q;
        while(q--) cin>>t,vis[t]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=(!vis[i]);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
