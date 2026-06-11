/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod    1000000007
#define PI 2*acos(0.0)
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};
//======================================ASIFAZAD==========================================//

bool ck(int n, int pos)
{
    return bool(n&(1<<pos));
}

int32_t main()
{
    io;
    int n;
    ll k;
    cin>>n>>k;
    vi adj(n+1);
    for(int i = 1; i<= n;i++)
        cin>>adj[i];
    vi vis(n+1), path;
    queue<int > q;
    q.push(1);
    vis[1] = 1;
    int ans;
    k++;
    while(k)
    {
        int ac =q.front();
        q.pop();
        if(vis[ac] && !path.empty())
        {
            int ind;
            for(ind = 0; ind < path.size(); ind++)
                if(path[ind] == ac)
                    break;
            int dev = path.size() - ind;
            //cout<<"k: " <<  k <<" dev: " << dev<<"\n";
            ans = path[(k-1)%dev + ind];
            break;
        }
        vis[ac] = 1;
        path.pb(ac);
        k--;
        q.push(adj[ac]);
    }
    cout<<(!k? path[path.size() - 1]: ans);
    return 0;
}
