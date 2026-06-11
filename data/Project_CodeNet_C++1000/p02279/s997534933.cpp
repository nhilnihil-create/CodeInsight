#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

typedef struct node Node;

#define PB push_back

struct node{
  int id;
  int depth;
  int before;
  vector<int> nexts;
};

void Calc(int,int);//引数：親ノード、深さ
void PrintNode();

vector<Node> nodes(100000);
int n;

int main(int argc,char* argv[]){
  bool flag[100000];
  int id,k,x,rootnode;

  memset(flag,0,sizeof(flag));

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>id>>k;
    for(int j=0;j<k;j++){
      cin>>x;
      nodes[id].nexts.PB(x);
      flag[x]=true;
    }
  }

  for(int i=0;i<n;i++){
    nodes[i].id=i;
    if(!flag[i])
      rootnode=i;
  }

  nodes[rootnode].before=-1;
  Calc(rootnode,0);
  PrintNode();

  return 0;
}

void Calc(int nowid,int depth){
  
  nodes[nowid].depth=depth;
  depth++;
  
  for(int i=0;i<(int)nodes[nowid].nexts.size();i++){
    nodes[nodes[nowid].nexts[i]].before=nodes[nowid].id;
    Calc(nodes[nowid].nexts[i],depth);
  }
}

void PrintNode(){
  Node tmp;
  for(int i=0;i<n;i++){
    tmp=nodes[i];
    cout<<"node "<<tmp.id<<": parent = "<<tmp.before<<", depth = "<<tmp.depth<<", ";

    if(tmp.before==-1)
      cout<<"root";
    else if((int)tmp.nexts.size()==0)
      cout<<"leaf";
    else
      cout<<"internal node";

    cout<<", [";
    for(int j=0;j<(int)tmp.nexts.size();j++){
      cout<<tmp.nexts[j];
      if(j!=(int)tmp.nexts.size()-1){
	cout<<", ";
      }
    }
    cout<<"]"<<endl;
  }
}