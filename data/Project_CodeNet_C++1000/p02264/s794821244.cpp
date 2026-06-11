#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> P;
main(){
  queue<P> proces;
  int n,q;
  string a;
  int b;
  int time=0;
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    proces.push(P(a,b));
  }
  while(!proces.empty()){
    P p;
    p=proces.front();
    proces.pop();
    if(p.second-q<=0){
      time+=p.second;
      cout<<p.first<<" "<<time<<endl;
    }
    else{
      time+=q;
      proces.push(P(p.first,p.second-q));
    }
  }
}