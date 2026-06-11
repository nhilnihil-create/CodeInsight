#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  unordered_map<string,long long>	s;
  long long ans=0;
  for(int i=0;i<n;i++){
    string t;	cin >> t;
    sort(t.begin(),t.end());
    if(s.count(t))	s[t]+=1;
    else	s[t]=1;
  }

  for(auto	p:s){
    long long x=p.second;
    ans+=x*(x-1)/2;
  }
  cout << ans;
}