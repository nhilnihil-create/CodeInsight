#include<iostream>
#include<vector>
using namespace std;
int main(){
  float n,m;
  cin>>n>>m;
  int cnt=0;
  vector<int> v;
  for(int i=0;i<=n-1;i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  int all_vote=0;
  for(auto& i:v){
    all_vote+=i;
  }
  float t;
  t=all_vote*(1/(4*m));
  int ans=0;
  for(auto& i:v){
    if(i>=t){
      ans+=1;
    }
  }
  if(ans>=m){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}