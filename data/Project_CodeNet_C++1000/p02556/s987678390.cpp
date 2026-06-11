#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  vector<int> rect(4,0);
  for(int i=0;i<n;i++){
    if(x[i]+y[i]>x[rect[0]]+y[rect[0]]){
      rect[0]=i;
    }
    if(x[i]-y[i]>x[rect[1]]-y[rect[1]]){
      rect[1]=i;
    }
    if(y[i]-x[i]>y[rect[2]]-x[rect[2]]){
      rect[2]=i;
    }
    if(x[i]+y[i]<x[rect[3]]+y[rect[3]]){
      rect[3]=i;
    }
  }
  cout<<max(abs(x[rect[0]]-x[rect[3]])+abs(y[rect[0]]-y[rect[3]]),abs(x[rect[1]]-x[rect[2]])+abs(y[rect[1]]-y[rect[2]]))<<endl;
}