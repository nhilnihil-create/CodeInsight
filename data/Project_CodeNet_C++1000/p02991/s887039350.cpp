#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 1e5+50, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
int vis[N][3] ;
vector < int > graph[N] ;
int n, m, t,s, u, v ;
int main()
{
    Tsetso
    cin >> n >> m ;
    for ( int i = 0 ; i < m ; i++)
    {
        cin >> u >> v ;
        graph[u].push_back(v);
    }
    cin >> s >> t ;
    queue < int > q ;
    q.push(s);
    vis[s][0] = 1 ;
    int cnt = 1 ;
    while ( q.size())
    {
        int y = q.size() ;
        for ( int i = 0 ; i < y ; i++)
        {
            for ( auto j : graph[q.front()])
            {
                if ( !vis[j][cnt%3])
                {
                    if ( cnt%3 == 0 && j == t )
                        return cout << cnt/3, 0 ;
                    q.push(j);
                    vis[j][cnt%3] = 1 ;
                }
            }
            q.pop();
        }
        cnt++ ;
    }
    cout << -1 ;
}
