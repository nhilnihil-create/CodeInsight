#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n,x,y;  cin >> n >> x >> y;

    unordered_map< int , vector< int > > adjacentList;

    for(int i=1;i<n;i++)
    {
        adjacentList[i].push_back(i+1);
        adjacentList[i+1].push_back(i);
    }
    adjacentList[x].push_back(y);
    adjacentList[y].push_back(x);

    unordered_map< int , int > mp;

    for(int i=1;i<n;i++)
    {
        int dist[n+1]={0};
        int visited[n+1]={0};
        queue< int > q;
        q.push(i);
        dist[i]=0;
        visited[i]=1;

        while(!q.empty())
        {
            int top = q.front();
            q.pop();

            for(int x : adjacentList[top])
            {
                if(visited[x]==0)
                {
                    visited[x]=1;
                    dist[x]=dist[top]+1;
                    q.push(x);
                }
            }
        }

        for(int j=i+1;j<=n;j++)
            mp[dist[j]]++;
    }

    for(int i=1;i<n;i++)
        cout << mp[i] << endl;


    return 0;
}
