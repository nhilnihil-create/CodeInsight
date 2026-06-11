#include <bits/stdc++.h>

using namespace std ;

const int inf = 1e9 ;
const int MAX = 1e5 + 10 ;

int arr[MAX] , dist[MAX][3] ;
int n , m ;

vector< vector<int> >adj(MAX) ;

void dijkstra(int s)
{
	for(int i = 0 ; i <= n ; ++i)
		dist[i][0] = dist[i][1] = dist[i][2] = inf ;
	priority_queue< array<int , 3> , vector< array<int , 3> > , greater< array<int , 3> > >q ;
	dist[s][0] = 0 ;
	q.push({0 , s , 0}) ;
	while(!q.empty())
	{
		int cost = q.top()[0] ;
		int node = q.top()[1] ;
		int x = q.top()[2] ;
		q.pop() ;
		if(dist[node][x] < cost)
			continue ;
		for(auto &child : adj[node])
		{
			int ncost = cost ;
			if(x == 2)
				ncost++ ;
			if(ncost < dist[child][(x+1)%3])
			{
				dist[child][(x+1)%3] = ncost ;
				q.push({ncost , child , (x+1)%3}) ;
			}
		}
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>m ;
	for(int i = 0 ; i < m ; ++i)
	{
		int x , y ;
		cin>>x>>y ;
		adj[x].push_back(y) ;
	}
	int s , t ;
	cin>>s>>t ;
	dijkstra(s) ;
	int ans = dist[t][0] ;
	if(ans == inf)
		ans = -1 ;
	return cout<<ans<<"\n" , 0 ;
}		