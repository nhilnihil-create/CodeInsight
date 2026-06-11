#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  vector<pair<string,int>>v;
  int n;
  cin>>n;
    int total_time=0;
  for(int i=0;i<n;i++){
      string play_list;
      int time;
      cin>>play_list>>time;
      v.push_back(make_pair(play_list,time));
      total_time+=time;
  }
  string s=v[0].first;
  string target;
  cin>>target;
  if(s==target)
  cout<<total_time - v[0].second<<endl;
  else{
    int res=0;
     int i;
    for(i=0;i<v.size();i++){
        if(v[i].first!=target){
        res+=v[i].second;
       }
        else
     break; 
    }
     cout<<total_time-res-v[i].second<<endl;
  }
}