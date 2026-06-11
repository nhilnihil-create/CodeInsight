#include<bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<char,int>mp;
  string s;
  cin>>s;
  for (auto x : s){
    mp[x]++;
  }
  for (auto x : mp){
    if (x.second!=2){
      cout<<"No";
        return 0;
    }
  }
  cout<<"Yes";
}
  
