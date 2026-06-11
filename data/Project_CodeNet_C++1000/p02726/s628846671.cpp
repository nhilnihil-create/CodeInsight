#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x, y, k;
vector <int> adj[2003];
int anss[2003];
int dist[2003];


void bfs(int v)
{
    for (int i = 1 ; i <= n; i++)
        dist[i] = -1;
    
    queue <int> fila;
    fila.push(v);
    dist[v] = 0;

    int aux;
    while(!fila.empty())
    {
        aux = fila.front();
        fila.pop();

        /* if (aux == destination)
            break; */

        int tam = adj[aux].size();
        for (int x = 0; x < tam; x++)
        {
            int neighboor = adj[aux][x];
            if (dist[neighboor] == -1)
            {
                dist[neighboor] = dist[aux] + 1;
                fila.push(neighboor);
            }
        }
            


    }
}


int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x >> y;

    for (int i = 1; i < n; i++){
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }

    adj[x].push_back(y);
    adj[y].push_back(x);

    for (int i = 1; i <= n; i++){
        bfs(i);
        for (int i = 1; i <= n; i++){
            anss[dist[i]] += 1;
        }
    }

    for (int i = 1; i < n; i++){
        cout << (anss[i] >> 1) << endl;
    }
    
 
    return 0;
}