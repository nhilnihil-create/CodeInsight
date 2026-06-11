#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define ll long long
#define     f           first
#define     s           second
#define     pb          push_back
#define     lb          lower_bound
#define     ub          upper_bound
#define     pii         pair<long long,long long>
#define     all(x)      x.begin(),x.end()
#define     fix         fixed<<setprecision(10)
#define     rep(i,a,b)  for(int i=int(a);i<=int(b);i++)

int n,m,ok[N];
set<int>v[N];
vector<int> temp;
void dfs(int x){
    int cnt=1;
    ok[x]=1;
    temp.pb(x);
    for(int u:v[x]) if(!ok[u]) dfs(u);
}
int main()
{
   cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].insert(b);
        v[b].insert(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!ok[i])
        {
            temp.clear();
            dfs(i);
            int k=temp.size();
            ans=max(ans,k);
        }
    }
    cout<<ans;

 // getch();
    return 0;
}