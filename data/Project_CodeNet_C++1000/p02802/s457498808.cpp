#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,m;
  cin>>n>>m;
  vector<string>p(m);
  vector<string>s(m);
  for(long long i=0;i<m;i++){
    cin>>p[i]>>s[i];
  }
  long long cnt=0;
  long long cnt2=0;
  map<string,int>mp;
  map<string,int>mp2;
  for(long long i=0;i<m;i++){
    if(s[i]=="AC"&&mp[p[i]]==0){
      mp[p[i]]++;
      cnt++;
      cnt2+=mp2[p[i]];
    }
    if(s[i]=="WA"&&mp[p[i]]==0){
      mp2[p[i]]++;
    }
  }
  cout<<cnt<<" "<<cnt2<< endl;
  return 0;
}