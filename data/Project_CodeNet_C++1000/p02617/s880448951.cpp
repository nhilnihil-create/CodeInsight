#include <iostream>
#include <vector>
using namespace std;

struct edge{
  int x;
  int y;
};

int main(){
  int N;
  cin>>N;
  vector<edge> edges;
  for(int i=0;i<N-1;i++){
    edge c;
    int a,b;
    cin>>a>>b;
    c.x=min(a,b);
    c.y=max(a,b);
    edges.push_back(c);
  }
  long long nodes=0;
  long long numedges=0;
  for(int i=1;i<=N;i++){
    nodes=nodes+(long long)i*(i+1)/2;
  }
  for(int i=0;i<N-1;i++){
    numedges=numedges+ (long long)edges[i].x * (N-edges[i].y+1);
  }
  cout<<nodes-numedges<<endl;
}
