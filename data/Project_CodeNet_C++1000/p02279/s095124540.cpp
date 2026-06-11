#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;
const int INF = 0x7fffffff;

int gcd(int x,int y){
  int mi,ma;
  ma = max(x,y);
  mi = min(x,y);
  if(ma % mi == 0){
    return mi;
  }
  else{
    return gcd(mi,ma % mi);
  }
}
struct Edge{
  int parent;
  int depth;
  vector<int> nodes;
};

int getDepth(int id,vector<Edge>* edges){

  int depth=0;
  int parent;
  while(id != -1){
    id = edges->at(id).parent;
    depth++;
  }
  return depth;
}

int main(){
  long ii,jj,kk;
  vector<int> a;
  int n;
  cin >> n;
  vector<Edge> edges;
  edges.resize(n);

  for(ii=0;ii<n;ii++){
    edges[ii].parent = -1;
    edges[ii].depth =  0;
  }
  
  int id,k;
  int tmp,child,parent;
  for(ii=0;ii<n;ii++){
    cin >> id >> k;
    edges[id].nodes.resize(k);

    //子供の分、回す
    for(jj=0;jj<k;jj++){
      //子供
      cin >> edges[id].nodes[jj] ;
      //tmp = edges[edges[id].nodes[jj]].parent;
      //親の設定
      edges[edges[id].nodes[jj]].parent = id;
      //深さの設定
      edges[edges[id].nodes[jj]].depth = edges[id].depth + 1;
    }
    
    //自分が親
    //if(edges[id].parent == -1){
    //  for(jj=0;jj<edges[id].nodes.size();jj++){
    //    for(kk=0;kk<edges[edges[id].
    //  }
    //}    
  }
  int depth;
  for(ii=0;ii<n;ii++){
    depth = getDepth(edges[ii].parent,&edges);
    cout << "node " << ii << ": parent = " << edges[ii].parent << ", depth = " << depth << ", ";

    if(edges[ii].parent == -1){
      cout << "root,";
    }
    else if(edges[ii].nodes.size() == 0){
      cout << "leaf,";
    }
    else{
      cout << "internal node,";
    }

    cout << " [";

    for(jj=0;jj<edges[ii].nodes.size();jj++){
      cout << edges[ii].nodes[jj] ;

      if(jj != edges[ii].nodes.size() -1){
        cout << ", ";
      }
    }
    
    cout << "]" << endl;
      
  }
  
  return 0;
}

