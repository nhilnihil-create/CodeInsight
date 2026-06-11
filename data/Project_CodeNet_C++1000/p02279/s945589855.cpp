#include <iostream>
#include <vector>
using namespace std;

int main(){
  int a,b,c,d,p[100001],n,k;
  vector<int> e[100001];
  cin>>a;
  for(int i=0;i<=a;i++)p[i]=-1;
  for(int i=0;i<a;i++){
    cin>>b>>c;
    for(int j=0;j<c;j++){
      cin>>d;
      p[d]=b;
      e[b].push_back(d);
    }
  }
  //cout<<"ttttttt";///////
  for(int i=0;i<a;i++){
    n=i;
    k=0;
    while(p[n]!=-1){
      n=p[n];
      k++;
    }
    cout<<"node "<<i<<": parent = "<<p[i];
    cout<<", depth = "<<k;
    if(p[i]==-1)cout<<", root, [";
    else if(e[i].size()==0)cout<<", leaf, [";
    else cout<<", internal node, [";

    for(int j=0;j<e[i].size();j++){
      cout<<e[i][j];
      if(e[i].size()-j==1);
      else cout<<", ";
    }
    cout<<"]\n";
    
  }
  return 0;
}