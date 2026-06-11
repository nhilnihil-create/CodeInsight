#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=0;
  map<string,int> d;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    if(d.count(s)){
      continue;
    }
    else{
      d[s]=1;
      ans+=1;
    }
  }
  cout<<ans<<endl;
  return 0;
}