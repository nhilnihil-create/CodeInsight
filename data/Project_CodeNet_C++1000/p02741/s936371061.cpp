#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
class Graph 
{ 
    int V;    
    list<int> *adj;    
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w);  
  
    // prints BFS traversal from a given source s 
    void BFS(int s);   
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) //How to add edge
{ 
    adj[v].push_back(w); 
} 
  
void Graph::BFS(int s) //BFS 
{ 
   
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
 
    list<int> queue; 
    visited[s] = true; 
    queue.push_back(s); 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} //To create a graph
//Graph g(4); 
    //g.addEdge(0, 1); 
    //g.addEdge(0, 2); 
int gcd(int x, int y) {
        if (x == 0) {
            return y;
        }
        
        return gcd(y % x, x);
    }


int main()
{
  int a[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int k;
  cin>>k;
  cout<<a[k-1]<<"\n";
   
   return 0;
}