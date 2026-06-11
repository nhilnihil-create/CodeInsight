#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int maxN = 5000;
int n,k;
vector<bool>vis(maxN+5);
vector<int>a(maxN+5);
vector<int>b(maxN+5);
vector<int>path;
void dfs(int i,int val)
{
    vis[i] = 1;
    val+=b[i];
    path.push_back(val);
    if (!vis[a[i]])dfs(a[i],val);
}
int32_t main()
{
    fastio;
    cin>>n>>k;
    for (int i = 0;i<n;i++){cin>>a[i];a[i]--;}
    for (int i = 0;i<n;i++)cin>>b[i];
    int fin = -1e20;
    for (int i = 0;i<n;i++){
        for (int i = 0;i<n;i++)vis[i] = 0;
        path.clear();
        dfs(i,0);
        int ans = -1e20;
        if (path.back()>0 && k>=(path.size())){
            int num = k/(path.size());
            int left = k%(path.size());
            int maxpos = -1e20;
            for (int j = 0;j<left;j++)maxpos = max(maxpos,path[j]);
            ans = num*(path.back()) + maxpos;
            maxpos = -1e20;
            for (int j = 0;j<path.size();j++)maxpos = max(maxpos,path[j]);
            ans = max(ans,(num-1)*(path.back())+maxpos);
        }
        else{
            for (int j = 0;j<min(k,(int)path.size());j++)ans = max(ans,path[j]);
        }
        fin = max(fin,ans);
    }
    cout<<fin;
    return 0;
}