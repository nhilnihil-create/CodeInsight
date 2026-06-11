   #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ff first
    #define ss second
    #define pb push_back
    #define vll vector<ll>
    #define mll map<ll,ll>
    #define MOD 1000000007
    #define pll pair<ll,ll>
constexpr ll INF = 1999999999999999997; 
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    int main() {
        fastio;

        int n,m;
        cin>>n>>m;
        vector<int>adj[n+1];
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
        }

         int s,t;
         cin>>s>>t;
        queue<pair<int,int>>q;
        q.push({s,0});
        int dist[n+1][3];
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                dist[i][j]=INT_MAX;
            }
        }
         dist[s][0]=0;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(auto j:adj[p.ff])
            {
                if(dist[j][(p.ss+1)%3]==INT_MAX)
                 {
                      dist[j][(p.ss+1)%3] = min((dist[p.ff][p.ss]+1), dist[j][(p.ss+1)%3]);
                      q.push({j,(p.ss+1)%3});
                 }
            }
        }
        if(dist[t][0]==INT_MAX)
        {
            cout<<-1<<endl;
        }
        else
        cout<<dist[t][0]/3<<endl;;


    }