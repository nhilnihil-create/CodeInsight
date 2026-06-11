#include<iostream>
#include<vector>
#include<cmath>
#define INF 0
using namespace std;

class segtree{
public:
  int Node;
  vector<int> table;
  segtree(int);
  int ope(const int,const int);
  void add(int index,const int value){ // index is 0-indexed.
    index += Node; // query function
    table[index] += value;
    while(index > 0){
      index /= 2;
      table[index] = ope(table[2*index],table[2*index+1]);
    }
  }
  int getsum(int l, int r);
};
int segtree::getsum(int l,int r){ // l,r is 0-indexed.
    if(l == r) return table[r+Node];
    l += Node; r += Node;
    long long ans = 0;
    for(; l <= r;l >>=1, r >>=1){
      if(r == l){ans=ope(ans,table[l]); return ans;}
      if(r%2 == 0) ans=ope(ans,table[r]),--r;
      if(l%2) ans=ope(ans,table[l]),++l;
    }
    return ans;
}
segtree::segtree(int Max_Node){  // initialize
  Node = 2;
  while(Node < Max_Node)
    Node *= 2;
  table.resize(2*Node);
  for(int i = Node;i < Node*2; i++)
    table[i] = INF; // initialize
  for(int i= Node-1; i > 0; i--)
    table[i] = ope(table[i*2],table[i*2+1]);
}

int segtree::ope(const int a,const int b){
  return a+b;
}

int main(){
  int n,q;
  cin>>n>>q;
  segtree seg(n);
  for(int i=0;i<q;i++){
    int com,x,y;
    cin>>com>>x>>y;
    if(com){
      cout<<seg.getsum(x,y)<<endl;
    }else{
      seg.add(x,y);
    }
  }
  return 0;
}