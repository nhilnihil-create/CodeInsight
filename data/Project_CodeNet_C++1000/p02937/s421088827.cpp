#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main(){
  string s, t;
  cin >> s >> t;
  vector<vector<int>> arf(26,vector<int>(0));
  for(int i=0; i<(int)s.size(); ++i){
    int x=s[i]-'a';
    arf[x].push_back(i+1);
  }
  for(int i=0; i<26; ++i){
    arf[i].push_back(INF);
  }
  long long ans=0;
  int num=0;
  for(int i=0; i<(int)t.size(); ++i){
    int x=t[i]-'a';
    if(arf[x].size() == 1){ cout << -1 << endl; return 0;}
    auto itr = upper_bound(arf[x].begin(),arf[x].end(),num);
    int newnum;
    if(*itr == INF) newnum = arf[x][0];
    else newnum = *itr;
    if(newnum <= num){
      ans += s.size() - num + newnum;
    }else{
      ans += newnum - num;
    }
    num = newnum;
  }
  cout << ans << endl;
}