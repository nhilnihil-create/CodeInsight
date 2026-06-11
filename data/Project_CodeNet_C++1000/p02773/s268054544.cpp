#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin>>N;
  map<string,int>mp;
  int max=0;
  for(long long i=0;i<N;i++){
    string S;
    cin>>S;
    mp[S]++;
    if(max<mp[S]){
      max=mp[S];
    }
  }
  vector<string>ans;
  for(auto X:mp){
    if(X.second==max){
      ans.push_back(X.first);
    }
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    cout<<ans.at(i)<< endl;
  }
}