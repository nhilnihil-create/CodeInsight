#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  string s;
  cin>>s;
  ll ans[s.size()+1],sum=0;
  for(int i=0;i<s.size()+1;i++){
    ans[i]=0;
  }
  for(int i=0;i<s.size();i++){
    if(s[i]=='<'){
      ans[i+1]=max(ans[i+1],ans[i]+1);
    }
  }
  for(int i=s.size()-1;i>=0;i--){
    if(s[i]=='>'){
      ans[i]=max(ans[i],ans[i+1]+1);
    }
  }
  for(int i=0;i<s.size()+1;i++){
    sum+=ans[i];
  }
  cout<<sum<<endl;
}