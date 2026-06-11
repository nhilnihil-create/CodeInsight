#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Unionfind{
    vector<int> parent;
    void init(int forestSize){
        parent.resize(forestSize);
        for(int i=0;i<forestSize;i++){parent.at(i)=i;}
    }
    int root(int v){
        if(parent.at(v)==v){return v;}
        else{return parent.at(v)=root(parent.at(v));}
    }
    bool belong(int x,int y){
        if(root(x)==root(y)){return true;}
        else{return false;}
    }
    void unite(int x,int y){
        if(parent.at(x)!=parent.at(y)){parent.at(root(y))=root(x);}
    }
    /*
    Unionfind<int> rock;
    rock.init(N);
    */
};
int main(){
  int N,Q;
  cin>>N>>Q;
  Unionfind<int> rock;
  rock.init(N);
  for(int i=0;i<Q;i++){
    int a,x,y;
    cin>>a>>x>>y;
    if(a==0){
      rock.unite(x,y);
    }
    else{
      if(rock.belong(x,y)){cout<<1<<endl;}
      else{cout<<0<<endl;}
    }
  }
}