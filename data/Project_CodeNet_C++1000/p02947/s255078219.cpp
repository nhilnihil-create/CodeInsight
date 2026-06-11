#include <bits/stdc++.h>
using namespace std;
long long combination(int n,int r){
  if(r==0 || r==n)return 1;
  else if (r==1)return n;
  return (combination(n-1,r-1)+combination(n-1,r));
}
int main(){
  int n;
  cin>>n;
  map<string,int> moji;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    moji[s]++;
  }
  long long ans=0;
  for(auto x:moji){
    int p=x.second;
    if(p==1)continue;
    ans+=combination(p,2);
  }
  cout<<ans<<endl;
  return 0;
}
