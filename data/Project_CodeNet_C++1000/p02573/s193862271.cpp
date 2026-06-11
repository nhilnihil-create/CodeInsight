#include <bits/stdc++.h>
using namespace std;

struct union_find{
  vector<int> r;
  union_find(int n){
    r=vector<int>(n,-1);
  }
  int root(int x){
    if(r[x]<0){
      return x;
    }else{
      return root(r[x]);
    }
  }
  bool unite(int a,int b){
    a=root(a);
    b=root(b);
    if(a==b){
      return false;
    }else{
      if(r[a]>r[b]){
        swap(a,b);
      }
      r[a]+=r[b];
      r[b]=a;
      return true;
    }
  }
  int size(int x){
    return -r[root(x)];
  }
};
  
int main(){
  int n,m;
  cin>>n>>m;
  int a,b;
  union_find u(n);
  for(int i=0;i<m;i++){
    cin>>a>>b;
    a--;
    b--;
    u.unite(a,b);
  }
  int M=1;
  for(int i=0;i<n;i++){
    M=max(u.size(i),M);
  }
  cout<<M<<endl;
}