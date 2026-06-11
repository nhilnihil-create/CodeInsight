#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000000007
#define fix(n) cout << fixed << setprecision(n)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(long i=a; i<=b; i++)
#define REN(i, a, b) for(long i=b; i>=a; i--)
// Debugging 
#define line cout << endl
#define out(n) cout << n << " "
#define bug(n) cout << n << "\n"
#define print(arr, start, end) REP(i, start, end) out(arr[i]); line

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef map<int, int> mii;

///// General Purpose functions /////

////////////////
int util(int s, vector<int> adj[], vector<bool> &visited)
{
  	visited[s] = true;
  	queue<int> q;
    q.push(s);
 	int l=0;
  
  	while(!q.empty())
    {
      int tmp = q.front();
      l++;
      q.pop();
      
       for(auto it = adj[tmp].begin(); it != adj[tmp].end(); it++)
       {
         if(visited[*it] == true) continue;
         visited[*it] = true;
         q.push(*it);
       }
    }
  
  	return l;
}


int bfs(vector<int> adj[], int V)
{
 	int len = 0;
  	vector<bool> visited(V, false);	
  	
  	for(int i=0; i<V; i++)
    {
      if(visited[i] == false)
      {
        int l = util(i, adj, visited);
        len = max(len, l);
      }
    }

  	return len;
}


void solve(){
	int V, m;
  	cin >> V >> m;
    int x,y;
    
  	vector<int> adj[V];
 	
  	for(int i=0; i<m; i++)
    {
      cin >> x >> y;
      adj[x-1].push_back(y-1);
      adj[y-1].push_back(x-1);
    }
  	
  	int max_len = bfs(adj, V);
	//out("a\n");
  	bug(max_len);
}

void prep(){

}

int main()
{
	//code
	io;
	int t = 1;
	//cin >> t;
	prep();
	fix(12);
	while(t--){
	    solve();
	}
	
	return 0;
}