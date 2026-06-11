#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>v(1e6+5);
    vector<int>vis(1e6+5);
    for(int i=0;i<n;i++){
        int tm;
        cin>>tm;
        if(vis[tm]==1){
            v[tm]=1;
            continue;
        }
        for(int i=2*tm;i<=1e6;i+=tm){
            v[i]=1;
        }

        vis[tm]=1;
    }
    int ans=0;
    for(int i=1;i<=1e6;i++){
        if(vis[i]&&!v[i])
            ans++;
    }
    cout<<ans<<'\n';
    return 0;

}
/***
5 4 1
1000000000 1000000000 1000000000 1000000000 1000000000
1000000000 1000000000 1000000000 1000000000
3 4 730
60 90 120
80 150 80 150
*/
