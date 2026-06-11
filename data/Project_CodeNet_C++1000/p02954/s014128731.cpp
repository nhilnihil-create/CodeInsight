#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  vector<int>ans(s.size(),0);
  int cnt=0;
  //まず左から見る
  for(int i=0;i<s.size()-1;i++){
    if(s.at(i)=='R'&&s.at(i+1)=='L'){
      ans[i]++;
      int tmp=cnt/2;
      //cout<<cnt<<endl;
      ans[i]+=tmp;
      ans[i+1]+=cnt-tmp;
      cnt=0;
    }
    else if(s.at(i)=='R'&&s.at(i)!='L'){
      ans[i]=0;
      cnt++;
    }
  }
  
  for(int i=s.size()-1;i>=1;i--){
    if(s.at(i-1)=='R'&&s.at(i)=='L'){
      ans[i]++;
      int tmp=cnt/2;
      ans[i]+=tmp;
      ans[i-1]+=cnt-tmp;
      cnt=0;
    }
    else if(s.at(i-1)!='R'&&s.at(i)=='L'){
      cnt++;
    }
  }

  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
}