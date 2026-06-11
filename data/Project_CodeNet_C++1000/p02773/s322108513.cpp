#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  map<string,int>mp;
  string temp;
  for(int i=0;i<N;i++){
    cin>>temp;
    mp[temp]++;
  }
 
  int maxn=0;
  for(auto it=mp.begin();it !=mp.end();it++){
    if(it->second >= maxn){
      maxn=it->second;
    }
  }
  for(auto it=mp.begin();it !=mp.end();it++){
    if(it->second == maxn){
      cout<<it->first<<endl;
    }
  }  
 
  return 0;
}
