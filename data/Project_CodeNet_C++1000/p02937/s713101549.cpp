#include <bits/stdc++.h>

using namespace std;

int main(){
  string s, t;
  map<char,vector<long long>> mp;
  cin >> s >> t;
  for(long long i=0;i<s.length();i++)mp[s[i]].push_back(i);
  for(int i=0;i<t.length();i++){
    if(mp[t[i]].size()==0){
      cout << -1 << endl;
      return 0;
    }
  }
  long long ans=0;
  long long cur=-1;
  map<char, long long> idx;
  for(int i=0;i<t.length();i++){
    char c = t[i];
    long long v_size=mp[c].size();
    while(idx[c]<v_size && mp[c][idx[c]]<=cur){
      idx[c]++;
    }
    if(idx[c]==mp[c].size()){
      for(auto& p: idx){
        idx[p.first]=0;
      }
      cur=mp[c][0];
      ans+=s.length();
    }
    else{
      cur=mp[c][idx[c]];
    }
  }
  char last = t[t.length()-1];
  ans += mp[last][idx[last]]+1;
  cout << ans << endl;
}

