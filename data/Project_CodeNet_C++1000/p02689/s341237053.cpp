#include<bits/stdc++.h>
using namespace std;

#define IOS             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define watch(x);       cout << "\n" <<  #x << " is: " << x << "\n";
#define ll              long long int
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define pb              push_back
#define nl              cout<<"\n"
#define gcd(a,b)        __gcd(a,b)
#define sq(a)           (a)*(a)
#define loop(i,a,b)     for (ll i = a; i <= b; i++)
#define rloop(i,a,b)    for (int i = a; i >= b; i--)
#define sz(a)           a.size()
#define mod             1000000007
#define PI              2*acos(0.0)


int main()
{
    IOS
    int T=1;
    //cin>>T;
    while(T--)
    {
        int V,E;
        cin >> V >> E;
        vector<int> adj[V];
        int h[V];
        loop(i,0,V-1) cin>>h[i];
        for(int i = 0; i < E; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ans=0;
        for(int i=0;i<V;i++)
        {
            int q=1;
            if(adj[i].size()==0)
            {
                ans++;
                continue;
            }
            for(int j=0;j<adj[i].size();j++)
            {
                if(h[i]<=h[adj[i][j]])
                {
                    q=0;
                    break;
                }
            }
            if(q) ans++;
        }
        cout<<ans;

    }
    return 0;
}
