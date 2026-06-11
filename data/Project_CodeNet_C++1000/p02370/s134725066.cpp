#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Vertex{
  int connection;
  int name;
  list<Vertex*> v_list;
  Vertex(int n):connection(0),name(n){}
  friend class Graph;
};

class Graph{
  vector<Vertex*> graph;
public:
  Graph(int size){
    graph.resize(size);
    for(int i=0;i<size;i++){
      graph[i]=new Vertex(i);
    }
  }

  ~Graph(){
    for(int i=0;i<(int)graph.size();i++){
      delete graph[i];
    }
  }

  void addEdge(int from,int to){
    graph[from]->v_list.push_back(graph[to]);
    graph[to]->connection++;
  }

  void topo(){
    Vertex *v;
    queue<Vertex*> q;
    vector<Vertex*> vec;

    for(int i=0;i<(int)graph.size();i++){
      if(graph[i]->connection==0) q.push(graph[i]);
    }

    while(!q.empty()){
      v=q.front();
      q.pop();
      vec.push_back(v);
      for(list<Vertex*>::iterator it=v->v_list.begin();it!=v->v_list.end();it++){
	Vertex* w=*it;
	if((--w->connection)==0){
	  q.push(w);
	}
      }
    }

    for(int i=0;i<(int)vec.size();i++){
      cout<<vec[i]->name<<endl;
    }

  }

};

int main(){
  int v=0;
  int e=0;
  cin>>v>>e;
  Graph graph(v);
  for(int i=0;i<e;i++){
    int from,to;
    cin>>from>>to;
    graph.addEdge(from,to);
  }
  graph.topo();
  return 0;
}