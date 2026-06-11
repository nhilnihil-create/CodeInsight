#include<iostream>
#include<vector>
using namespace std;
vector<int>node[200005];
int counter[200005]={0};

void dfs(int pos,int from);
int main(){
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  
  for(int i=0;i<q;i++){
    int index,data;
    cin>>index>>data;
    index--;
    counter[index]+=data;
  }

  dfs(0,0);
  for(int i=0;i<n-1;i++){
    cout<<counter[i]<<' ';
  }
  cout<<counter[n-1]<<endl;
  return(0);
}

void dfs(int pos,int from){
  for(int i=0;i<node[pos].size();i++){
    int next=node[pos][i];
    if(next!=from){
      counter[next]+=counter[pos];
      dfs(next,pos);
    }
  }
  return;
}