#include<bits/stdc++.h>
using namespace std;
int N;
vector<vector<pair<int,int>>> Data;
bool judge(int bit){
  for(int i=0;i<N;i++){
    if(!(bit&(1<<i)))continue;
    for(auto v:Data[i]){
      int x=v.first;
      int y=v.second;
      if(y==0&&(bit&(1<<x)))return false;
      if(y==1&&!(bit&(1<<x)))return false;
    }
  }
  return true;
}
int main(){
  cin>>N;
  Data.resize(N);
  for(int i=0;i<N;i++){
    int tmp;
    cin>>tmp;
    for(int j=0;j<tmp;j++){
      int a,b;
      cin>>a>>b;a--;
      Data[i].push_back(make_pair(a,b));
    }
  }

int ans=0;
for(int bit=0;bit<(1<<N);bit++){
  if(judge(bit)){
    int cnt=0;
    for(int i=0;i<N;i++){
      if(bit&(1<<i))cnt++;
    }
    ans=max(ans,cnt);
  }
}
cout<<ans<<endl;
}
