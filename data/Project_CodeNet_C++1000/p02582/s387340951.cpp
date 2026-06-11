#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  string s;
  cin>>s;
  vector<int> v;
  int aq=0;
  
  for(int i=0;i<3;i++){
    if(s[i]=='R')  aq++;
    else {
      v.push_back(aq);
      aq=0;
    }

 if(i==2&&s[i]=='R') v.push_back(aq);
  }
 
 
  int ans=0;
  for(int j=0;j<3;j++){
    if(v[j]>ans) ans=v[j];
  }
  cout<<ans<<endl;
  return 0;
}