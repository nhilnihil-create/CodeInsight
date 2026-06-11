#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 2e5+5;

int n , m , s , t;
vector<int> adj[N];

int bfs()
{
    queue< pair<int,int> > q;
    int d[n+2][4];
    for(int i=1; i<=n; i++)
    {
        d[i][0]=1e8 , d[i][1] =1e8 , d[i][2] = 1e8;
    }
    q.push({s , 0});
    d[s][0] = 0;

    while(q.size())
    {
        int node = q.front().f , mod = q.front().s;
        q.pop();

        for(auto ch : adj[node])
        {
            int m = (mod+1)%3;
            if (d[ch][m] == 1e8)
            {
                d[ch][m] = d[node][mod]+1;
                q.push({ch,m});
            }
        }
    }

    if (d[t][0] == 1e8) return -1;
    else return d[t][0]/3;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cin >> s >> t;
    cout << bfs() << '\n';
//
    return 0;
}