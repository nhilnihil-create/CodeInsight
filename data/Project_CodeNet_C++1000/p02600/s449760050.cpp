#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;

bool bfs(int s,int d,vector<vector<int>> &v,vector <bool> &vis)
{
    for (int i=0;i<vis.size();++i)
        vis[i]=false;
    queue<int> q;
    if (s==d)
        return true;
    vis[s]=true;
    q.push(s);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for (auto it:v[x]){
            if (it==d)
                return true;
            if (vis[it])
                continue;
            vis[it]=true;
            q.push(it);
        }

    }
    return false;
}

void fun(int k){
        int n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        int ans[55][55]={0};

        vector<vector<int>> v(55);
        vector<bool> vis(55);

        for (int i=0;i<n;++i)
        {
            for (int j=0;j<n;++j)
            {
                if (i==j)
                    continue;
                if (b[i]=='Y' && a[j]=='Y' && abs(i-j)==1)
                    v[i+1].push_back(j+1);
            }
        }

        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (bfs(i,j,v,vis))
                    ans[i][j]=1;
            }
        }
        
        cout<<"Case #"<<k<<":"<<endl;
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (ans[i][j])
                    cout<<"Y";
                else
                    cout<<"N";
            }
            cout<<endl;
        }
}

signed main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n;
   cin>>n;
  if (n>=400 && n<=599)
      cout<<8<<endl;
  else if (n>=600 && n<=799)
      cout<<7<<endl;
  else if (n>=800 && n<=999)
      cout<<6<<endl;
  else if (n>=1000 && n<=1199)
      cout<<5<<endl;
  else if (n>=1200 && n<=1399)
      cout<<4<<endl;
  else if (n>=1400 && n<=1599)
      cout<<3<<endl;
  else if (n>=1600 && n<=1799)
      cout<<2<<endl;
  else if (n>=1800 && n<=1999)
      cout<<1<<endl;

}
