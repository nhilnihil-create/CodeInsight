#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){

  int N;
  cin>>N;
  int max=0;
  vector<string>S(N);
  map<string,int>data; 
  for(int i=0;i<=N-1;i++){
  
    cin>>S[i];
    data[S[i]]++;
    if(data[S[i]]>max){
    
      max=data[S[i]];
    }
  }
  vector<string>ans(1);
  int count=0;
  for(auto i=data.begin();i!=data.end();i++){
  
    if(i->second==max){
  
      ans[count]=i->first;
      count++;
      i->second=0;
    }
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<=count-1;i++){
  
    cout<<ans[i]<<endl;
  }
  return 0;
}