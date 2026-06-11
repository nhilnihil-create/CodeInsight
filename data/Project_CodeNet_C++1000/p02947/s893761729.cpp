#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  map<string,int> m;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    m[s]+=1;
  }
  long long int ans=0;
  for(auto a:m){
    long long int hoge=a.second;
    if(hoge==1)continue;
    //cout<<(hoge*hoge-hoge)/2<<endl;
    ans+=(hoge*hoge-hoge)/2;
  }
  cout<<ans<<endl;
  return 0;
}