#include <bits/stdc++.h>

using namespace std;
const int N=1005;
int ok[N];
int cur[N];
int a[N][N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1;i<=n;i++)
        for(int j=0;j<n-1;j++)
            cin>>a[i][j];

    int ans=0,cnt=0;
    vector<int>v,t;
    for(int i=1;i<=n;i++)
        v.push_back(i);
    while(1)
    {
        if(v.empty())
            break;
        ans++;
        for(auto i:v)
        {
            int p=a[i][cur[i]];
            if(ok[i]==ans||ok[p]==ans)
                continue;
            if(a[p][cur[p]]==i)
            {
                cnt++;
                cur[i]++;
                cur[p]++;
                if(cur[i]!=n-1)
                    t.push_back(i);
                if(cur[p]!=n-1)
                    t.push_back(p);
                ok[p]=ok[i]=ans;
            }
        }
        t.swap(v);
        t.clear();
    }
    if(n*(n-1)/2!=cnt) ans=-1;
    cout<<ans<<endl;
    return 0;
}
