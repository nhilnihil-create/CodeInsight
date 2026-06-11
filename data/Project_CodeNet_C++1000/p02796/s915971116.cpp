#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> d;
  for(int i=0;i<n;i++){
    int x,l;
    cin>>x>>l;
    d.push_back({x-l,1,i});
    d.push_back({x+l,0,i});
  }
  sort(d.begin(),d.end());
  int a=0;
  vector<bool> c(n,1);
  queue<int> q;
  for(int i=0;i<(int)d.size();i++){
    int x=d.at(i).at(0);
    int f=d.at(i).at(1);
    int j=d.at(i).at(2);
    if(f==0){
      if(c.at(j)){
        a++;
        while(!q.empty()){
          c.at(q.front())=0;
          q.pop();
        }
      }
    }else
      q.push(j);
  }
  cout<<a<<endl;
}