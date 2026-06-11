#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  string tmp;
  int64_t ans=0;
  map<string,int>s;
  for(int i=0;i<n;i++){
    cin>>tmp;
    sort(tmp.begin(),tmp.end());
    if(s.count(tmp)){
      ans+=s.at(tmp);
      s.at(tmp)++;
    }
    else s[tmp]=1;
  }
  cout <<ans<<endl;
}